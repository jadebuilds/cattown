# klipper.py
# 
# Socket-based control over Klipper 3D printing software in order to 
# send gcodes and collect status from a control board running Klipper.
#
# Author: Jade



from typing import Union
import sys, socket, select, errno, time, json, math
import threading
from queue import Queue

from ..constants import Point
from ..motion import MotionCommand, DirectMove
from ..gcodes import GCode, UseAbsoluteCoordinates
from .driver import MotionDriver

class MockMotionDriver(MotionDriver):

    def __init__(self, speed_mm_s: float, update_rate_s: float = 0.1):
        self.speed_mm_s = speed_mm_s
        self.update_rate_s = update_rate_s
        self.lock = threading.Lock()
        self.mouse_location = Point(0.0, 0.0)
        self.motion_queue = Queue()
        self.current_motion = None
        self.should_exit = threading.Event()
        self.thread = threading.Thread(target=self._run, daemon=True)
        self.thread.start()


    def get_current_position(self) -> Point:
        """
        Get the current location.
        """
        with self.lock:
            return self.mouse_location

    def enqueue_motion(self, motion: MotionCommand):
        """
        Add motion to the queue.
        """
        with self.lock:
            self.motion_queue.put(motion)

    @abstractmethod
    def clear_queue(self) -> Point:
        """
        Make a best effort to sweep the queue of upcoming moves.

        Return the location that the mouse will be in when it's done executing
        any irreversible moves -- ie that've been submitted to the Klipper socket
        (since Klipper doesn't seem to feature rollback).
        """
    
    @abstractmethod
    def stop(self):
        """
        Shut down nicely / clean up / end threads / whatever
        """


    def _run(self):
        while not self.should_exit:
            time.sleep(self.update_rate_s)
            if not self.current_motion:
                self.current_motion = self.motion_queue.get()  # will block background thread if empty
                if type(self.current_motion) is not DirectMove:
                    raise NotImplementedError  # I'm only mocking DirectMoves for the moment (will worry about others later)
                
                # Calculate distance
                x_distance = (self.current_motion.destination.x_mm - self.mouse_location.x_mm)
                y_distance = (self.current_motion.destination.y_mm - self.mouse_location.y_mm)
                total_distance = math.sqrt(x_distance**2 + y_distance**2)

                # Update by some 
                with self.lock:
                    # TODO is this how this works?
                    self.mouse_location.x_mm += (x_distance / total_distance) * (self.speed_mm_s * self.update_rate_s)
                    self.mouse_location.y_mm += (y_distance / total_distance) * (self.speed_mm_s * self.update_rate_s)


class KlipperSocket(MotionDriver):

    def __init__(self, socket_path: str):
        """
        socket_path: The full filename of the Unix domain socket.

        socket_path can be found by running systemctl status | grep klipper ;
        it's passed to the Klipper executable using the -a flag,.
        """
        self.webhook_socket = self._webhook_socket_create(socket_path)
        self.poll = select.poll()
        self.poll.register(self.webhook_socket, select.POLLIN | select.POLLHUP)
        self.socket_data = b""
        self.thread = threading.Thread(target=self._thread_run, daemon=True)
        self.should_close = threading.Event()  # set() to stop the thread from running
        self.thread.start()

        # keep an integer command id
        self.next_cmd_id = 0  # incrementing ID for commands
        self.next_cmd_id_lock = threading.Lock()  # is this needed?

        # Default to absolute coordinates
        self.enqueue_motion(UseAbsoluteCoordinates())

        # Subscribe to toolhead position
        # er, let's start out by seeing what objecst there are -- TODO remove me
        self._send_command({
                "method": "objects/list", 
            })

    def get_current_position(self) -> Point:
        raise NotImplementedError  # todo how do I do this???? maybe using objects/subscribe?

    def enqueue_motion(self, motion: Union[MotionCommand, GCode]):
        """
        Enqueue a series of gcode commands to the printer
        """
        if isinstance(motion, MotionCommand):
            gcodes = motion.to_g_code()  # type: List[GCode]
        elif isinstance(motion, GCode):
            gcodes = [motion]  # because sometimes we want to enqueue like just a UseAbsoluteCoordinates

        for gcode in gcodes:  # todo figure out how to submit them all as scripts
            self._send_command({
                "method": "gcode/script", 
                # TODO does this work? how does one submit multiple g-codes, what's the delimiter?
                # (jade to dig into the Klipper source)
                # TODO also: should we submit multiple short scripts? that might make more sense bc that way
                # we could get finer grained feedback on progress from Klipper
                "params": {"script": gcode.to_str()}
            })

    def clear_queue(self):
        """
        TODO: break down paths into bite size chunks, then enqueue and submit them chunk at a time
        so that we don't have to ask Klipper to clear? I think gcode/restart will not work
        """
        raise NotImplementedError

    def _send_command(self, command: dict):
        with self.next_cmd_id_lock:
                command['id'] = self.next_cmd_id
                self.next_cmd_id += 1
        
        cmd_str = json.dumps(command, separators=(',', ':'))
        print(f"Sending: {cmd_str}")
        self.webhook_socket.send(cmd_str.encode('ascii') + b"\x03")

    def _webhook_socket_create(self, uds_filename):
        sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
        sock.setblocking(0)
        sys.stderr.write("Waiting for connect to %s\n" % (uds_filename,))
        while 1:
            try:
                sock.connect(uds_filename)
            except socket.error as e:
                if e.errno == errno.ECONNREFUSED:
                    time.sleep(0.1)
                    continue
                sys.stderr.write("Unable to connect socket %s [%d,%s]\n"
                                % (uds_filename, e.errno,
                                    errno.errorcode[e.errno]))
                sys.exit(-1)
            break
        sys.stderr.write("Connection.\n")
        return sock

    def _process_socket(self):
        data = self.webhook_socket.recv(4096)
        if not data:
            sys.stderr.write("Socket closed\n")
            sys.exit(0)
        parts = data.split(b'\x03')
        parts[0] = self.socket_data + parts[0]
        self.socket_data = parts.pop()  # what does this do?? I'm confused
        for line in parts:
            print(f"Got from socket: {line}")

    def _thread_run(self):
        while not self.should_close.is_set():
            events = self.poll.poll(1000.)  # indicates receive ready (is this necessary?)
            if events:
                self._process_socket()
            else:
                print("no events")

    def stop(self):
        self.should_close.set()


class MoonrakerSocket(MotionDriver):

    def __init__(self, hostname: str):
        """
        Takes the hostname of the Pi that we're communicating with and 
        sends it G-code through the .
        """

    def enqueue_motion(self, motion: MotionCommand):
        return super().enqueue_motion(motion)

    def get_current_position(self) -> Point:
        return super().get_current_position()
    
    def clear_queue(self):
        return super().clear_queue()
    
    def stop(self):
        return super().stop()

    