from abc import abstractmethod, ABCMeta
from typing import List

from ..core.types import Trajectory, CatState
from ..motion_controller import MotionController

class Personality(metaclass=ABCMeta):
    """
    Abstract base class for personalities.
    """

    def __init__(self, motion_controller: MotionController) -> None:
        """
        At initialization we ask for a handle to the Platform Manager so that 
        """
        self.motion_controller = motion_controller

    @abstractmethod
    def update_cat_state(self, cat_states: List[CatState]):
        """
        Called by main() to update the personality on where the cat is and what it's up to
        """

    @abstractmethod
    def get_trajectory(self) -> Trajectory:
        """
        Okay, you know where the cat is: where shall we go next?
        """