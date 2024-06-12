from typing import Union, List
import threading
import time
import logging

from ..constants import Point
from queue import Queue
from .driver import MotionDriver, PositionUpdateCallback
from .commands import MotionCommand
from .gcodes import GCode


logger = logging.getLogger(__name__)


class MockMotionDriver(MotionDriver):

    def __init__(self,update_rate_s: float = 0.1):
        self.update_rate_s = update_rate_s
        self.toolhead_location = Point(13.0, 197.0)  # Start at tile (3, 5), which is free on the Open Sauce map
        self.gcode_queue = Queue()
        self.position_callbacks = []
        self.should_exit = threading.Event()
        self.thread = threading.Thread(target=self._run, daemon=True)
        self.thread.start()


    def get_current_position(self) -> Point:
        """
        Get the current location.
        """
        return self.toolhead_location

    def enqueue_motion(self, motion: Union[GCode, MotionCommand, List[GCode]]):
        """
        Add motion to the queue.
        """
        if isinstance(motion, MotionCommand):
            gcodes = motion.to_g_code()
        elif isinstance(motion, list):  # literally there's no way to check if it's List[GCode] smh
            gcodes = motion
        elif isinstance(motion, GCode):
            gcodes = [motion]
        else:
            raise TypeError(f"Unsupported motion type {type(motion)} ({motion})")

        logger.debug(f"Putting {len(gcodes)} items in the mock motion queue")
        for gcode in gcodes:
            self.gcode_queue.put(gcode)
    
    def stop(self):
        """
        Shut down nicely / clean up / end threads / whatever
        """

    def subscribe_to_position(self, position_callback: PositionUpdateCallback) -> None:
        """
        Sign up to receive synchronous callbacks whenever we get a new position
        from Klipper. These should please not block! Or else who knows what will happen!
        Thank youuuuuuuu love you bye
        """
        self.position_callbacks.append(position_callback)


    def _run(self):
        logger.info("Starting MockMotionDriver background thread")
        while not self.should_exit.is_set():
            time.sleep(self.update_rate_s)
            next_gcode: GCode = self.gcode_queue.get()  # will block background thread if empty
            logger.debug("popped gcode from queue")
            # It's a mock, so we'll just do one move 

        
            self.toolhead_location = next_gcode.end_coordinates()
            for callback in self.position_callbacks:
                callback(self.toolhead_location)