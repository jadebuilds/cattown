from typing import List, Optional
from enum import Enum
from ..constants import Tile, Path
from ..path_finder import PathFinder
import time
import random
from dataclasses import dataclass


@dataclass
class CatState:
    is_present: bool
    distance: float


class MouseState(Enum):
    HIDING = 0
    TEASING = 1
    FLEEING = 2


THRESHOLD_NEAR = 50.0
THRESHOLD_FAR = 100.0


class RelativeMove(Enum):
    """
    Note that this repeats from motion.commands.RelativeMove, except
    that that is a direct motion command which computes to G-code, and
    this is a tool for generating Path objects (lists of tiles).

    TODO reconcile these somehow
    """

    Left = (-1, 0)
    Right = (1, 0)
    Up = (0, 1)
    Down = (0, -1)


TEASE_SPEED = 250.0  # mm/s
TEASE_ROUTINES = {
    "wiggle in the box": [
        RelativeMove.Up,
        RelativeMove.Down,
        RelativeMove.Up,
        RelativeMove.Down,
    ],
    "stick our nose out": [
        # Exit the box (starting from the very back of the house)
        RelativeMove.Up,
        RelativeMove.Left,
        RelativeMove.Left,
        RelativeMove.Down,
        RelativeMove.Down,
        # Then go back in
        RelativeMove.Up,
        RelativeMove.Up,
        RelativeMove.Right,
        RelativeMove.Right,
        RelativeMove.Down,
    ],
}


class Mouse:
    """
    Implements a state machine for the mouse.

    Currently thinks entirely in terms of map coordinates (because
    that's the simplest way to do it)
    """

    def __init__(self, location: Tile, houses: List[Tile], path_finder: PathFinder):
        self.state = (
            MouseState.FLEEING
        )  # If we're not in a house, run to the nearest house
        self.location = location
        self.houses = houses
        self.path_finder = path_finder

        self.time_last_state_change: Optional[float] = None  # plz use time.monotonic()

        # Gonna see if I can
        self.explanation: str = ""

    def move(self, cat_state: CatState) -> Optional[Path]:
        """
        Decide what to do!

        Note re: variable duration: if the mouse wants to wait, I'm figuring that
        the easiest way to handle it is just to sleep here. So the mouse may either
        return a path it wants to run right away or time.sleep within this function.
        """

        if self.state == MouseState.HIDING:
            """
            Hide for a certain amount of time
            """
            if cat_state.is_present:
                if cat_state.distance > THRESHOLD_NEAR:
                    self._explain("Cat not near, may exit...")
                    if random.random() < 0.1:  # 10% chance of exiting each second
                        self._change_state(MouseState.TEASING)
                        self._explain("Time to explore :)")
                        return
            else:  # wait a second
                self._explain("Cat too close! Will keep hiding")
            time.sleep(1)

        elif self.state == MouseState.TEASING:
            """
            We're starting out by doing this the dumbest way possible,
            just by executing a predefined move and 
            """
            self._change_state(MouseState.HIDING)
            # TODO capture the timestamp for when we end the tease routine, not when we start it
            return random.choice(TEASE_ROUTINES)

        elif self.state == MouseState.FLEEING:
            """
            Flee to the nearest house
            """
            if self.location in self.houses:
                # We've arrived at a house, let's hide there for a while
                self._change_state(MouseState.HIDING)
                # Note that I'm waiting to do this change until we're called
                # again so that we'll have the right timestamp for it
            else:
                # Flee to nearest house
                return self._to_nearest_house()

    def _change_state(self, new_state: MouseState):
        self.state = new_state
        self.time_last_state_change = time.monotonic()

    def _time_in_state(self) -> float:
        return time.monotonic() - self.time_last_state_change

    def _to_nearest_house(self) -> Path:
        """
        Figure out what the nearest house to flee to is.
        Currently doing so in a really brute-force way -- just computing
        paths to every house and picking the one that crosses the fewest tiles!
        """
        house_paths = [self.path_finder.go_to_coords(house) for house in self.houses]
        shortest_path = min([len(path) for path in house_paths])
        for path in house_paths:
            if len(path) == shortest_path:
                return path

    def _to_path(self, location: Tile, routine: List[RelativeMove]) -> Path:
        """
        Convert a routine of relative moves into absolute tile coordinates
        so we can send it to the toolhead (cheesy!)
        """
        path = [location]
        for move in routine:
            path.append(path[-1] + move.value)
        return path

    def _explain(self, to_log: str):
        """
        Set a message to the frontend somehow which explains why we're
        in the current state
        """
        # Currently just doing this bullshit thing
        self.explanation = to_log
