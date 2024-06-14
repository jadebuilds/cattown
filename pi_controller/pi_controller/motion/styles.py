from abc import ABCMeta, abstractmethod
from typing import List, Tuple
import logging
import math

from ..constants import Tile, Path, Point
from .gcodes import GCode, LinearMove, ArcMove
from ..custommap import MapConfig, to_coordinates


logger = logging.getLogger(__name__)


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

    def __init__(self, speed_mm_s: float, map_config: MapConfig):
        self.speed_mm_s = speed_mm_s
        self.map_config = map_config

    def generate_motion(self, path_segment: List[Tile]) -> List[GCode]:
        return [
            LinearMove.from_point(to_coordinates(tile, self.map_config), speed_mm_s=self.speed_mm_s)
            for tile in path_segment
        ]


class ZigZag(MotionStyle):

    def __init__(self, speed_mm_s: float):
        self.speed_mm_s = speed_mm_s
    
    def generate_motion(self, path_segment: List[Tile]) -> List[GCode]:
        """
        Another TODO: Redo Squiggles but as a sawtooth.
        Yet another TODO: How do we do lookahead????? This is actually pretty important for cornering.
        I will probably just do it without lookahead to start...
        """
        raise NotImplementedError
    




# --------------------------------------------------------------------------- #
# PATHING
# --------------------------------------------------------------------------- #

# More advanced MotionCommands that execute a path.

MapVector = Tuple[int, int]

# some unit vectors
RIGHT = (1, 0)
LEFT = (-1 , 0)
UP = (0, 1)
DOWN = (0, -1)


class ArcSquiggles(MotionStyle):
    """
    A funky lil pass at "simplest possible wiggly mouse-like motion."
    Converts direct motion into 45º arcs, joining one segment to the next
    so that the mouse corners well.

    Note that the bugs were kinda annoying to iron out here and I ended up
    relying heavily on this interactive G-Code viewer here:

    https://ncviewer.com/

    It's so good, lets you plot the whole path and tweak and re-plot and stuff.
    Try it out! Don't develop without it or similar :)
    """

    def __init__(self, map_config: MapConfig, speed_mm_s: float):
        """
        Accepts a path defined in map coordinates -- integer positions -- and the data
        necessary to convert it to millimeter board coordinates. That way we can use
        standard-sized arcs and .

        Note that this currently assumes that each segment in the path is one length long
        and goes to an adjacent neighbor (up, down, left, right).
        """
        super().__init__()
        self.map_config = map_config
        self.speed_mm_s = speed_mm_s

    def generate_motion(self, path_segment: Path) -> List[GCode]:
        """
        Generate g-code. This is a stateful operation in which we traverse the path
        and replace each segment with either one arc occupying a full grid spacing unit
        or two half-grid-spacing arcs. This lets us align motion so that the mouse is 
        always turning the right direction into corners.
        """
        
        last_arc_clockwise = True  # whether the previous arc was CW or CCW. We'll start CCW (why not)
        last_segment_corner = False  # whether the last arc was a corner. 
        
        # We'll start out with a direct move to the first point just in case (hopefully a no-op)
        gcodes = []

        for segment_num in range(len(path_segment) - 1):
            logger.debug(f"segment number: {segment_num}")
            logger.debug(f"  > start: {path_segment[segment_num]}, end: {path_segment[segment_num + 1]}")
            this_direction = self._segment_direction(path_segment[segment_num], path_segment[segment_num + 1])
            try:
                next_direction = self._segment_direction(path_segment[segment_num + 1], path_segment[segment_num + 2])
            except IndexError:
                next_direction = this_direction  # TODO this is a dumb workaround do better
            
            logger.debug(f"This direction: {this_direction}, next direction: {next_direction}")

            # if we're continuing straight from a previous segment we'll flip the curl to wiggle back and forth.
            # otherwise if we're coming out of a corner then we'll continue in the same curl to complete the corner.
            start_arc_clockwise = last_arc_clockwise if last_segment_corner else (not last_arc_clockwise)
            logger.debug(f"  > arc should start {"clockwise" if start_arc_clockwise else "counterclockwise"}")

            if this_direction == next_direction:
                # When we're going in in a straight line we don't need to worry about prepping for the next corner,
                # so we can feel sure that we can keep going
                logger.debug("  > next segment is in a straight line, so we can do a full arc")
                gcodes.extend(self._full_arc(
                    start=path_segment[segment_num],
                    end=path_segment[segment_num + 1],
                    clockwise=start_arc_clockwise
                    ))
                logger.debug(f"    > {gcodes[-1].to_str()}")    

                # Record state for next iteration
                last_segment_corner = False
                last_arc_clockwise = start_arc_clockwise
            
            else:
                # OK, we're going to turn a corner into the next segment. We'll need to make sure that we enter
                # that corner with the appropriate curvature.
                
                next_corner_cross_product = this_direction[0] * next_direction[1] - this_direction[1] * next_direction[0]
                next_corner_clockwise = (next_corner_cross_product < 0)  # TODO confirm this please
                logger.debug(f"  > next segment is a corner going {"clockwise" if next_corner_clockwise else "counterclockwise"}")

                if start_arc_clockwise == next_corner_clockwise:
                    logger.debug(f"    > we're starting in the right curl, we'll keep that curl for the whole segment")
                    # if the last arc doesn't match the curl of the corner, one full arc will turn us in the right direction
                    gcodes.extend(self._full_arc(
                        start=path_segment[segment_num],
                        end=path_segment[segment_num + 1],
                        clockwise=start_arc_clockwise  # we still wanna start this segment respecting the last corner
                    ))
                    last_arc_clockwise = start_arc_clockwise
                    logger.debug(f"    > {gcodes[-1].to_str()}")    
                
                elif start_arc_clockwise != next_corner_clockwise:
                    logger.debug(f"    > we'll do a double half arc to flip our curl into the upcoming corner's curl")
                    # we want to end this segment with a curl matching the corner we're entering. If e.g. the last arc
                    # was CW and we want to end this segment CW, then we'll need to do two half arcs.
                    gcodes.extend(self._two_half_arcs(
                        start=path_segment[segment_num],
                        end=path_segment[segment_num + 1],
                        first_arc_clockwise=start_arc_clockwise
                    ))
                    last_arc_clockwise = not start_arc_clockwise  # the second arc is curled opposite the first
                    logger.debug(f"    > {gcodes[-2].to_str()}, {gcodes[-1].to_str()}")    

                # Record state for next segment
                last_segment_corner = True
        
        logger.debug("final segment!")
        # Final segment! We don't care about preparing an upcoming corner (assuming we'll stop), so this can just be a full arc:
        # TODO should we worry about making these paths play nicely with one another? IDK
        gcodes.extend(self._full_arc(
            start=path_segment[-2],
            end=path_segment[-1],
            clockwise=last_arc_clockwise if last_segment_corner else not last_arc_clockwise  # we still care about this tho
            ))

        return gcodes

    @staticmethod
    def _segment_direction(start: Tile, end: Tile) -> MapVector:
        dir = (end[0] - start[0], end[1] - start[1])
        assert abs(dir[0] + dir[1]) == 1, "I only know how to handle 1-length steps (up, left, right, or down)! Sorry!"
        return dir

    @staticmethod
    def _arc_center_offsets(direction: MapVector, clockwise: bool) -> Tuple[float, float]:
        """
        Figure out the I and J offsets for the center of a given arc, given its direction and curl.

        Offsets are sized relative to one full grid step (1.0).
        """
    
        # TODO there's gotta be a cleaner way to do this!!
        if direction == RIGHT:
            i = 0.5
            j = -0.5 if clockwise else 0.5
        elif direction == LEFT:
            i = -0.5
            j = 0.5 if clockwise else -0.5
        elif direction == UP:
            j = 0.5
            i = 0.5 if clockwise else -0.5
        elif direction == DOWN:
            j = -0.5
            i = -0.5 if clockwise else 0.5
        else:
            raise ValueError(f"Unsupported direction {direction} for arc center (expecting 1-length vector in a cardinal direction!)")

        return i,j

    def _full_arc(self, start: Tile, end: Tile, clockwise: bool) -> Tuple[ArcMove]:
        """
        Returns a Tuple[Arc] with one Arc in it. 
        
        Note that the type signature is (A) for consistency with _two_half_arcs, 
        (B) to allow PiecewiseLinearArcSquiggle to use multiple LinearMoves in place of the one
        ArcMove and keep the method signature the same!
        """
        dir_vec = self._segment_direction(start, end)

        i, j = self._arc_center_offsets(direction=dir_vec, clockwise=clockwise)

        return (ArcMove(
            x_mm=end[0] * self.map_config.map_grid_spacing_mm + self.map_config.map_x_offset,
            y_mm=end[1] * self.map_config.map_grid_spacing_mm + self.map_config.map_y_offset,
            i_mm= i * self.map_config.map_grid_spacing_mm,
            j_mm = j * self.map_config.map_grid_spacing_mm,
            clockwise=clockwise,
            speed_mm_s=self.speed_mm_s
        ),)
    
    def _two_half_arcs(self, start: Tile, end: Tile, first_arc_clockwise: bool) -> Tuple[ArcMove, ArcMove]:
        """
        Construct a segment which is two half-sized arcs. This segment starts and end with the same curl --
        if the last arc was clockwise, we'll do a small counterclockwise arc and then another clockwise
        """
        dir_vec = self._segment_direction(start, end)

        # The two arcs have different curl (clockwiseness). Note that since I and J are offsets from the
        # starting position of the arc, which I'm adjusting below when I construct the two arc moves,
        # I don't have to handle the offset between arcs here / do anything except twiddle the clockwise bit!
        i_1, j_1 = self._arc_center_offsets(dir_vec, first_arc_clockwise)
        i_2, j_2 = self._arc_center_offsets(dir_vec, not first_arc_clockwise)
        # I really wish I had element-wise multiplication like with np arrays or R vectors or whatever here...
        i_1, i_2, j_1, j_2 = i_1 * 0.5, i_2 * 0.5, j_1 * 0.5, j_2 * 0.5

        midpoint = (start[0] + 0.5 * dir_vec[0], start[1] + 0.5 * dir_vec[1])  # halfway between start to end

        return (
            ArcMove(
                x_mm=midpoint[0] * self.map_config.map_grid_spacing_mm + self.map_config.map_x_offset,
                y_mm=midpoint[1] * self.map_config.map_grid_spacing_mm + self.map_config.map_y_offset,
                i_mm= i_1 * self.map_config.map_grid_spacing_mm,
                j_mm = j_1 * self.map_config.map_grid_spacing_mm,
                clockwise=first_arc_clockwise,
                speed_mm_s=self.speed_mm_s
            ),
            ArcMove(
                x_mm=end[0] * self.map_config.map_grid_spacing_mm + self.map_config.map_x_offset,
                y_mm=end[1] * self.map_config.map_grid_spacing_mm + self.map_config.map_y_offset,
                i_mm= i_2 * self.map_config.map_grid_spacing_mm,
                j_mm = j_2 * self.map_config.map_grid_spacing_mm,
                clockwise=not first_arc_clockwise,
                speed_mm_s=self.speed_mm_s
            )
        )



class PiecewiseLinearArcSquiggles(ArcSquiggles):
    """
    CLASS INHERITANCE BAYBEE LFG

    This child class patches ArcSquiggles to generate piecewise linear arcs, because Klipper takes arcs slowly 
    for no discernable reason. Curse you Klipper! Some day we'll interpret our own gcode *shakes fist at sky*
    """

    @staticmethod
    def _arc_linear_approximation(start: Point, end: Point, i, j, segments=3) -> List[Point]:
        """ ChatGPT code, seems OK??? but might deserve closer review!!! """
        center_x = start.x_mm + i
        center_y = start.y_mm + j
        R = math.sqrt(i**2 + j**2)
        
        theta_0 = math.atan2(-j, -i)
        theta_1 = math.atan2(end.y_mm - center_y, end.x_mm - center_x)
        
        if theta_1 < theta_0:
            theta_1 += 2 * math.pi
        
        points = []
        delta_theta = (theta_1 - theta_0) / segments
        
        for k in range(segments + 1):
            theta_k = theta_0 + k * delta_theta
            X_k = center_x + R * math.cos(theta_k)
            Y_k = center_y + R * math.sin(theta_k)
            points.append(Point(X_k, Y_k))
        
        return points

    def _full_arc(self, start: Tile, end: Tile, clockwise: bool) -> Tuple[ArcMove]:

        start_coords = to_coordinates(start, self.map_config)
        end_coords = to_coordinates(end, self.map_config)

        dir_vec = self._segment_direction(start, end)
        i, j = self._arc_center_offsets(direction=dir_vec, clockwise=clockwise)
        grid_mm = self.map_config.map_grid_spacing_mm

        return (
            LinearMove.from_point(point, speed_mm_s=self.speed_mm_s)
            for point in self._arc_linear_approximation(start_coords, end_coords, i * grid_mm, j * grid_mm)
        )

    def _two_half_arcs(self, start: Tuple[int], end: Tuple[int], first_arc_clockwise: bool) -> Tuple[ArcMove]:
        dir_vec = self._segment_direction(start, end)

        # The two arcs have different curl (clockwiseness). Note that since I and J are offsets from the
        # starting position of the arc, which I'm adjusting below when I construct the two arc moves,
        # I don't have to handle the offset between arcs here / do anything except twiddle the clockwise bit!
        i_1, j_1 = self._arc_center_offsets(dir_vec, first_arc_clockwise)
        i_2, j_2 = self._arc_center_offsets(dir_vec, not first_arc_clockwise)
        # I really wish I had element-wise multiplication like with np arrays or R vectors or whatever here...
        i_1, i_2, j_1, j_2 = i_1 * 0.5, i_2 * 0.5, j_1 * 0.5, j_2 * 0.5

        midpoint = (start[0] + 0.5 * dir_vec[0], start[1] + 0.5 * dir_vec[1])  # halfway between start to end

        start_coords = to_coordinates(start, self.map_config)
        midpoint_coords = to_coordinates(midpoint, self.map_config)
        end_coords = to_coordinates(end, self.map_config)

        grid_mm = self.map_config.map_grid_spacing_mm

        return tuple(
            LinearMove.from_point(point, speed_mm_s=self.speed_mm_s)
            for point in self._arc_linear_approximation(start_coords, midpoint_coords, i_1 * grid_mm, j_1 * grid_mm)
        ) + tuple(
            LinearMove.from_point(point, speed_mm_s=self.speed_mm_s)
            for point in self._arc_linear_approximation(midpoint_coords, end_coords, i_2 * grid_mm, j_2 * grid_mm)
        )


if __name__ == "__main__":
    map_config = MapConfig(10.0, 0.0, 0.0, 50, 50)
    squiggle = ArcSquiggles(
        speed_mm_s=10000, map_config=map_config
    )
    # Points:
    # 3 4 5
    # 2 7 6
    # 1 8 B C
    # 0 9 A

    gcodes = squiggle.generate_motion(
        [
            (0, 0), (0, 1), (0, 2), (0, 3),
            (0, 4), (1, 4), (2, 4), (3, 4),
            (4, 4), (4, 3), (4, 2), (4, 1),
            (4, 0), (3, 0), (2, 0), (1, 0),
            (1, 1), (1, 2), (2, 2), (3, 2), (3, 3),
            (3, 4), (4, 4),
        ])
    for i, gcode in zip(range(len(gcodes)), gcodes):
        #print(f"{i+1}: {gcode.to_str()}")
        print(f"{gcode.to_str()}")  # for g-code plotter at https://ncviewer.com/
