from abc import abstractmethod, ABCMeta
from typing import List

from ..core.types import Trajectory, CatState


class Personality(metaclass=ABCMeta):
    """
    Abstract base class for personalities.
    """

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