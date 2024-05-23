from abc import ABCMeta, abstractmethod
from dataclasses import dataclass
from enum import Enum
from typing import List
from .gcodes import GCode, UseAbsoluteCoordinates, UseRelativeCoordinates, LinearMove, ArcMove


class Direction(Enum):
    Left = "l"
    Right = "r"
    Up = "u"
    Down = "d"


@dataclass
class Point:  # assumed to use absolute millimeter coordinates
    x_mm: float
    y_mm: float


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
    
    def __init__(self, destination: Point, speed_mm_s: float):
        super().__init__()
        self.destination = destination
        self.speed_mm_s = speed_mm_s

    def to_g_code(self) -> List[GCode]:
        return [LinearMove(x_mm=self.destination.x_mm, y_mm=self.destination.y_mm, speed_mm_s=self.speed_mm_s)]


class RelativeMove(MotionCommand):
    """
    For canned routines like exiting a mouse house or dropping off a toy back in a mouse house.
    """

    def __init__(self, direction: Direction, distance_mm: float, speed_mm_s: float) -> None:
        super().__init__()
        self.distance_mm = distance_mm
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
            UseRelativeCoordinates,  # temporary -- we'll put it back
            LinearMove(x_mm=x, y_mm=y, speed_mm_s=self.speed_mm_s),
            UseAbsoluteCoordinates  # let's use absolute coordinates by default!! please

        ]


class RoundedLineSegmentPath(MotionCommand):
    """
    Given a series of points, navigate between them, except round off each corner between 
    start and destination. Note that this means that we will not actually visit the coordinates
    of the intermediate points, i.e. points[1:-1]; we'll get close to them.

    TODO if we do a 180º turnaround, ie two successive line segments that are 180º from one another,
    will the M204 manage to slow down and speed up appropriately? or will we need to break that down
    into discrete G1s?

    Currently suggesting to the same size arc at each corner. Probably want to vary this with speed
    or something 🤔 but I figure we can do that as a second pass
    """

    def __init__(self, points: List[Point], arc_length_mm: float, speed_mm_s: float):
        self.points = points
        self.arc_length_mm = arc_length_mm
        self.speed_mm_s = speed_mm_s
    
    def to_g_code(self) -> List[GCode]:
        raise NotImplementedError  # 😇 todo
    

        