import threading
from ..constants import Point
from queue import Queue
from .driver import MotionDriver
from .commands import MotionCommand


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

    def clear_queue(self) -> Point:
        """
        Make a best effort to sweep the queue of upcoming moves.

        Return the location that the mouse will be in when it's done executing
        any irreversible moves -- ie that've been submitted to the Klipper socket
        (since Klipper doesn't seem to feature rollback).
        """
    
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
