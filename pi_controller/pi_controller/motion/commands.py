# motion.py
#
# Higher-level motion classes that take more abstract directions, such as
# map paths, and convert to movement sequences of gcodes.
# 
# Author: Jade


from abc import ABCMeta, abstractmethod
from dataclasses import dataclass
from enum import Enum
from typing import List, Tuple

from .gcodes import GCode, UseAbsoluteCoordinates, UseRelativeCoordinates, LinearMove, ArcMove
from ..constants import Path, Tile, MapConfig
from ..custommap import to_coordinates


class Direction(Enum):
    Left = "l"
    Right = "r"
    Up = "u"
    Down = "d"


# --------------------------------------------------------------------------- #
# MOTION COMMANDS
# --------------------------------------------------------------------------- #



class MotionCommand(metaclass=ABCMeta):
    """
    Abstract base class (so it must be extended to be instantiatable)
    for motion commands to be sent to the 3D printer. Meant to be higher
    level than GCodes -- so kinda convenience functions describing the actual
    kinds of movement we want to do.
    """
    
    @abstractmethod
    def to_g_code(self) -> List[GCode]:
        """
        Render into a series of GCodes that can be sent to the printer
        """

   
class DirectMove(MotionCommand):
    ""
    
    def __init__(self, destination: Tile, speed_mm_s: float, map_config: MapConfig):
        super().__init__()
        self.destination = destination
        self.speed_mm_s = speed_mm_s
        self.map_config = map_config

    def to_g_code(self) -> List[GCode]:
        dest_coords = to_coordinates(self.destination, self.map_config)
        return [
            LinearMove(x_mm=dest_coords.x_mm, y_mm=dest_coords.y_mm, speed_mm_s=self.speed_mm_s)
        ]


class RelativeMove(MotionCommand):
    """
    For canned routines like exiting a mouse house or dropping off a toy back in a mouse house.
    """

    def __init__(self, direction: Direction, steps: int, speed_mm_s: float, map_config: MapConfig) -> None:
        """
        Move a certain number of 
        """
        super().__init__()
        self.distance_mm = map_config.map_grid_spacing_mm * steps
        self.direction = direction
        self.speed_mm_s = speed_mm_s

    def to_g_code(self) -> List[GCode]:
        
        x, y = 0.0, 0.0

        if self.direction == Direction.Right:
            x = self.distance_mm
        elif self.direction == Direction.Left:
            x = -1 * self.distance_mm
        elif self.direction == Direction.Up:
            y = self.distance_mm
        elif self.direction == Direction.Down:
            y = -1 * self.distance_mm

        return [
            UseRelativeCoordinates(),  # temporary -- we'll put it back
            LinearMove(x_mm=x, y_mm=y, speed_mm_s=self.speed_mm_s),
            UseAbsoluteCoordinates(),  # let's default to absolute coordinates please!!!
        ]

