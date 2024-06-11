# moonraker.py
# 
# Connects to the Moonraker API using JSON-RPC and websockets.
# 
# Author: Jade

from typing import Optional, List, Union
import websockets
import json
import threading
import time
import websockets
import threading
import logging
import websockets.sync
import websockets.sync.client

from .driver import MotionDriver, PositionUpdateCallback
from .commands import MotionCommand
from .utils import ThreadSafeMonotonicCounter
from ..constants import Point
from .gcodes import GCode


PRIMARY_WEBSOCKET_URL = "ws://{hostname}/websocket"
BRIDGE_WEBSOCKET_URL = "ws://{hostname}/klipper"  # just in case it's useful


logger = logging.getLogger(__name__)


class MoonrakerSocket(MotionDriver):

    def __init__(self, hostname: str):
        """
        Given the hostname of a machine we can connect to it.

        For remote devices, should usually be of the format "cattown###.local".
        For local devices, ... what? I don't actually know yet
        """

        self.hostname = hostname
        self.ws = websockets.sync.client.connect(
            PRIMARY_WEBSOCKET_URL.format(hostname=hostname)
        )

        self.next_cmd_id = ThreadSafeMonotonicCounter()

        # ~~~~ STATE ~~~~ #
        # All of these should be protected by self.state_lock, thanks!
        self._state_lock = threading.Lock()
        self._position_callbacks = []
        self._last_update_timestamp: float = 0  # as a Klipper eventtime (TODO what are they?)
        self._current_location: Optional[Point] = None  # Last reported location
        self._gcodes_queued = []  # Moves that are queued up and will be submitted to Klipper
                                  # as soon as it gets hungry for more gcodes (yum)
        self._gcodes_submitted = []  # Moves that have been submitted to Klipper and can never
                                     # be revoked, so help us God, but don't appear to be done yet

        # Start a worker thread to receive messages from the socket.
        # N.B. there's probably some fancy way to do this using async but I am a 
        # synchronous kinda girl and I have no fucking clue how async works and 
        # no desire to start learning now lol! 
        # I'm like a grandmother looking down her pince-nez at your gosh darned fancy new iPad
        self.rx_thread = threading.Thread(target=self._receive, daemon=True)
        self.should_exit = threading.Event()  # thread will need to access this once start()'ed
        self.rx_thread.start()
        
        # Subscribe to motion report so we can get those sweet live position updates
        self._send({
            "method": "printer.objects.subscribe",
             "params": {
                 "objects": {
                     "motion_report": None,
                 }
             }
        })

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~ MotionDriver API ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    def enqueue_motion(self, motion: Union[GCode, List[GCode], MotionCommand]):
        if isinstance(motion, MotionCommand):
            gcodes = motion.to_g_code()  # type: List[GCode]
        elif isinstance(motion, GCode):
            gcodes = [motion]  # because sometimes we want to enqueue like just a UseAbsoluteCoordinates
        else:
            gcodes = motion  # should be List[GCode] (but there's no way to check that in runtime because Python's type system is hot garbage)

        for gcode in gcodes:
            self._send({
                "method": "printer.gcode.script", 
                # TODO should we submit multiple g-codes in a single script? what's the delimiter?
                # (jade to dig into the Klipper source)
                "params": {"script": gcode.to_str()}
            })

    def get_current_position(self) -> Point:
        """
        Get the current position from Moonraker
        """
        if not self._current_location:
            # If we haven't heard a location yet, wait up to two seconds
            logger.info("We haven't ")
            t_now = time.monotonic()
            t_timeout = t_now + 2.0
            while time.monotonic < t_timeout:
                if (self._current_location):
                    break
                time.sleep(0.1)

            raise TimeoutError("Unable to get a position from Moonraker :(")

        return self._current_location
    

    def subscribe_to_position(self, position_callback: PositionUpdateCallback) -> None:
        with self._state_lock:
            self._position_callbacks.append(position_callback)

    def stop(self):
        self.ws.close()
    
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Websocket stuff ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    def _send(self, message: dict):
        """
        Populate default fields like jsonrpc and ID, then send over the websocket.
        """
        message["jsonrpc"] = "2.0"
        message["id"] = self.next_cmd_id.get()
        self.ws.send(json.dumps(message))


    def _receive(self):
        """
        Infinite loop of receiving from the websocket, as a child thread so that
        it can run in the background.
        """
        while not self.should_exit.is_set():
            try:
                message: str = self.ws.recv(timeout=0.5)  # takes up to half a second to clean up
            except TimeoutError:
                continue

            data = json.loads(message)
        
            try:
                new_location = None

                # Our very first message is an objects.subscribe, which thoughtfully responds with
                # a readout of the motion_report object (similar to an objects/query maybe?)
                # that we can use:
                if data.get('id', None) == 0:  # notify_status_update messages don't have an ID so we'll get() with a default
                    eventtime = data['result']['eventtime']
                    pos_4d = data['result']['status']['motion_report']['live_position']   # X, Y, Z, E I'm pretty sure
                    new_location = Point(pos_4d[0], pos_4d[1])

                # After that we'll get a stream of differently formatted notify_status_update
                # messages which have the thing we need!
                elif data['method'] == 'notify_status_update':
                    print("got notify_status_update")
                    eventtime = data['params'][1]  # pretty sure! why is it not labeled? idk
                    print(f"  > eventtime: {eventtime}")
                    pos_4d = data['params'][0]['motion_report']['live_position']
                    new_location = Point(pos_4d[0], pos_4d[1])
                    print(f"  > pos4d: {pos_4d}")
                    # TODO how do I flow-control this to not repeat this code?
                
                if new_location:
                    print(f"Got location! {self._current_location}")
                    with self._state_lock:
                        self._current_location = Point(pos_4d[0], pos_4d[1])
                        self._last_update_timestamp = eventtime
                        for callback in self._position_callbacks:
                            callback(new_location)

            except KeyError:
                print(f"No motion_report to see here: {message}")
                pass  # TODO set up logging so we can trace-level log here


if __name__ == "__main__":
    moonraker = MoonrakerSocket("cattown001.local")
    time.sleep(10)
