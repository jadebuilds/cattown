from abc import ABCMeta, abstractmethod
from typing import List

from ..constants import Tile
from .gcodes import GCode, LinearMove
from ..custommap import to_coordinates



class MotionStyle(metaclass=ABCMeta):

    @abstractmethod
    def generate_motion(self, path_segment: List[Tile]) -> List[GCode]:
        """
        Convert a segment of path into actual motion, expressed as gcodes.
        """


class SimpleArcSquiggles(MotionStyle):
    """
    Okay, I'm including this as an expression of intent (port over from
    SimpleSquiggleArcPath) but honestly it's probably not even worth the
    effort, because Klipper arcs are just unexpectedly slow... 
    or at least we can't figure out how to get it to run them at full 
    acceleration. Which is annoying! I really wanna have squiggly motion!
    So I'm going to stick to larger geometric constructions... or at least 
    see about generating my own piece-wise arc-like squiggles.
    """

    def generate_motion(self, path_segment: List[Tile]) -> List[GCode]:
        raise NotImplementedError  # TODO port over from the MotionCommand


class SimpleStraightLines(MotionStyle):

    def __init__(self, speed_mm_s: float):
        self.speed_mm_s = speed_mm_s

    def generate_motion(self, path_segment: List[Tile[int]]) -> List[GCode]:
        return [
            LinearMove.from_point(to_coordinates(tile), speed_mm_s=self.speed_mm_s)
            for tile in path_segment
        ]


class ZigZag(MotionStyle):

    def __init__(self, speed_mm_s: float):
        self.speed_mm_s = speed_mm_s
    
    def generate_motion(self, path_segment: List[Tile[int]]) -> List[GCode]:
        """
        Another TODO: Redo Squiggles but as .
        Yet another TODO: How do we do lookahead????? This is actually pretty important for cornering.
        I will probably just do it without lookahead to start...
        """
        raise NotImplementedError