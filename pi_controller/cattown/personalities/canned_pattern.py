from typing import List
import itertools
from pygcode import GCode

from ..core.types import Trajectory, CatState
from .base import Personality

class DoesCannedPattern(Personality):
    """
    The dumbest possible personality I can think of: loops through a series of predefined GCode moves.
    """

    def __init__(self, moves: List[GCode]):
        self.moves = moves
        self._iterator = itertools.cycle(moves)

    def update_cat_states(self, cat_states: List[CatState]):
        pass  # doesn't look at the cat lol

    def get_trajectory(self) -> Trajectory:
        """
        Note: Assumes that execute_trajectory() is synchronous/blocking and that we won't be called to generate
        a new trajectory until we're done with the last one. Is that a good pattern? Should we do it a different way?
        """
        return next(self._iterator)
    