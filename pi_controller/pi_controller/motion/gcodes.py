# gcodes.py
#
# Representation of gcode operations themselves as classes.
# (Note: I think this ought to exist somewhere? But I haven't found it?)
#
# Author: Jade

from abc import ABCMeta, abstractmethod
from enum import Enum
from typing import Optional

from ..constants import Point


class GCode(metaclass=ABCMeta):
    
    @abstractmethod
    def to_str(self) -> str:
        """
        Render the GCode as a string that can be sent to the Klipper socket.
        """

    @abstractmethod
    def end_coordinates(self) -> Optional[Point]:
        """
        Where will this gcode end, assuming absolute coordinates? 
        
        Note that absolute coordinates is considered the default, and consumers of 
        this function should bear in mind that individual gcodes won't know whether
        the machine is in absolute or relative modes, and should maintain their
        own state or whatever to figure that out if the need to!
        """


class Rotation(Enum):
    """
    Enum for use in Arcs mostly
    """
    Clockwise = "cw"
    CounterClockwise = "ccw"


class UseAbsoluteCoordinates(GCode):
    
    def to_str(self) -> str:
        return "G90"

    def end_coordinates(self) -> Optional[Point]:
        return None  # won't change coordinates

class UseRelativeCoordinates(GCode):

    def to_str(self) -> str:
        return "G91"
    
    def end_coordinates(self) -> Optional[Point]:
        return None

class SetAccelerationLimit(GCode):

    def __init__(self, limit_mm_s2: float) -> None:
        self.limit_mm_s2 = limit_mm_s2
    
    def to_str(self) -> str:
        """
        Use T for travel -- Cat Town only travels, it never prints
        (the other three parameters address printing operations)

        See: https://marlinfw.org/docs/gcode/M204.html
        """
        return f"M204 T{self.limit_mm_s2}"

    def end_coordinates(self) -> Optional[Point]:
        return None

class LinearMove(GCode):

    def __init__(self, x_mm: float, y_mm: float, speed_mm_s: float) -> None:
        self.x_mm = x_mm
        self.y_mm = y_mm
        self.speed_mm_s = speed_mm_s
    
    def to_str(self) -> str:
        """
        G0 is travel without extrusion at maximum rate (on a CNC it's 
        "move without cutting" and G1 is "move while cutting"). Here we'll actually
        use G1 (the "move while cutting") so that we can control speed
        with the F (feedrate) parameter.
        """
        return f"G1 X{self.x_mm} Y{self.y_mm} F{self.speed_mm_s * 60}"  # note that F is feedrate per minute (!)
    
    def end_coordinates(self) -> Optional[Point]:
        return Point(self.x_mm, self.y_mm)

class ArcMove(GCode):

    def __init__(self, x_mm: float, y_mm: float, i_mm: float, j_mm: float, clockwise: bool, speed_mm_s: float) -> None:
        """
        These are surprisingly confusing to me.

        x_mm: Destination X coordinate (other end of the arc)
        y_mm: Destination Y coordinate ("")
        i_mm: X offset of the arc center
        y_mm: Y offset of the arc center
        clockwise: True if you wanna go clockwise else False

        There's a great visualization of this in the Marlin docs:
        https://marlinfw.org/docs/gcode/G002-G003.html
        """
        self.x_mm = x_mm
        self.y_mm = y_mm
        self.i_mm = i_mm
        self.j_mm = j_mm
        self.clockwise = clockwise
        self.speed_mm_s = speed_mm_s

    def to_str(self) -> str:
        cmd = "G2" if self.clockwise else "G3"
        return f"{cmd} X{self.x_mm} Y{self.y_mm} I{self.i_mm} J{self.j_mm} F{self.speed_mm_s * 60}"  # note that F is feedrate per minute (!)
 
    def end_coordinates(self) -> Optional[Point]:
        return Point(self.x_mm, self.y_mm)
    