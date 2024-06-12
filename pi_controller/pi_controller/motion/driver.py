# driver.py
# 
# Base class for motion drivers.
# 
# Author: Jade

from typing import Union, List, Protocol
from abc import ABCMeta, abstractmethod

from ..constants import Point
from .commands import MotionCommand
from .gcodes import GCode


class PositionUpdateCallback(Protocol):
    """
    Predefined function signature for motion callbacks
    (because if only we were writing Rust smh).

    Ref: https://stackoverflow.com/questions/57837609/python-typing-signature-typing-callable-for-function-with-kwargs
    """

    def __call__(self, current_position: Point) -> None:
        """
        Callbacks should accept only the current position as a Point, thanks 🙏
        """


class MotionDriver(metaclass=ABCMeta):

    @abstractmethod
    def get_current_position(self) -> Point:
        """
        Get the current location.
        """

    @abstractmethod    
    def enqueue_motion(self, motion: Union[GCode, MotionCommand, List[GCode]]):
        """
        Add motion to the queue. This is considered irreversible -- once motion is
        enqueued we don't expect to take it back. If you want to queue up motion and
        then change your mind, consider using a Toolhead!
        """

    @abstractmethod
    def subscribe_to_position(self, position_callback: PositionUpdateCallback) -> None:
        """
        Sign up to receive synchronous callbacks whenever we get a new position
        from Klipper. These should please not block! Or else who knows what will happen!
        Thank youuuuuuuu love you bye
        """
