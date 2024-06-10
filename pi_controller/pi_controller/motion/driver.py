# driver.py
# 
# Base class for motion drivers.
# 
# Author: Jade

from abc import ABCMeta, abstractmethod

from ..constants import Point
from .commands import MotionCommand

class MotionDriver(metaclass=ABCMeta):

    @abstractmethod
    def get_current_position(self) -> Point:
        """
        Get the current location.
        """

    @abstractmethod    
    def enqueue_motion(self, motion: MotionCommand):
        """
        Add motion to the queue.
        """

    @abstractmethod
    def clear_queue(self):
        """
        Make a best effort to sweep the queue of upcoming moves. This will be 
        """

