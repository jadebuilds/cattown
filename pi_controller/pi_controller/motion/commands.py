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
from .constants import Path, Node, MapConfig
from .custommap import to_coordinates


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
    
    def __init__(self, destination: Node, speed_mm_s: float, map_config: MapConfig):
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


class SimpleSquigglePath(MotionCommand):
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

    def __init__(self, map_path: Path, map_config: MapConfig, speed_mm_s: float):
        """
        Accepts a path defined in map coordinates -- integer positions -- and the data
        necessary to convert it to millimeter board coordinates. That way we can use
        standard-sized arcs and .

        Note that this currently assumes that each segment in the path is one length long
        and goes to an adjacent neighbor (up, down, left, right).
        """
        super().__init__()
        self.map_path = map_path  # List[Node]
        self.map_config = map_config
        self.speed_mm_s = speed_mm_s

    def to_g_code(self) -> List[GCode]:
        """
        Generate g-code. This is a stateful operation in which we traverse the path
        and replace each segment with either one arc occupying a full grid spacing unit
        or two half-grid-spacing arcs. This lets us align motion so that the mouse is 
        always turning the right direction into corners.
        """
        
        last_arc_clockwise = True  # whether the previous arc was CW or CCW. We'll start CCW (why not)
        last_segment_corner = False  # whether the last arc was a corner. 
        
        # We'll start out with a direct move to the first point just in case (hopefully a no-op)
        gcodes = [
            LinearMove(
                x_mm=self.map_path[0][0] * self.map_config.map_grid_spacing_mm + self.map_config.map_x_offset,
                y_mm=self.map_path[0][1] * self.map_config.map_grid_spacing_mm + self.map_config.map_y_offset,
                speed_mm_s=self.speed_mm_s
            )
        ]

        for segment_num in range(len(self.map_path) - 2):
            print(f"segment number: {segment_num}")
            print(f"  > start: {self.map_path[segment_num]}, end: {self.map_path[segment_num + 1]}")
            this_direction = self._segment_direction(self.map_path[segment_num], self.map_path[segment_num + 1])
            next_direction = self._segment_direction(self.map_path[segment_num + 1], self.map_path[segment_num + 2])
            print(f"This direction: {this_direction}, next direction: {next_direction}")

            # if we're continuing straight from a previous segment we'll flip the curl to wiggle back and forth.
            # otherwise if we're coming out of a corner then we'll continue in the same curl to complete the corner.
            start_arc_clockwise = last_arc_clockwise if last_segment_corner else (not last_arc_clockwise)
            print(f"  > arc should start {"clockwise" if start_arc_clockwise else "counterclockwise"}")

            if this_direction == next_direction:
                # When we're going in in a straight line we don't need to worry about prepping for the next corner,
                # so we can feel sure that we can keep going
                print("  > next segment is in a straight line, so we can do a full arc")
                gcodes.append(self._full_arc(
                    start=self.map_path[segment_num],
                    end=self.map_path[segment_num + 1],
                    clockwise=start_arc_clockwise
                    ))
                print(f"    > {gcodes[-1].to_str()}")    

                # Record state for next iteration
                last_segment_corner = False
                last_arc_clockwise = start_arc_clockwise
            
            else:
                # OK, we're going to turn a corner into the next segment. We'll need to make sure that we enter
                # that corner with the appropriate curvature.
                
                next_corner_cross_product = this_direction[0] * next_direction[1] - this_direction[1] * next_direction[0]
                next_corner_clockwise = (next_corner_cross_product < 0)  # TODO confirm this please
                print(f"  > next segment is a corner going {"clockwise" if next_corner_clockwise else "counterclockwise"}")

                if start_arc_clockwise == next_corner_clockwise:
                    print(f"    > we're starting in the right curl, we'll keep that curl for the whole segment")
                    # if the last arc doesn't match the curl of the corner, one full arc will turn us in the right direction
                    gcodes.append(self._full_arc(
                        start=self.map_path[segment_num],
                        end=self.map_path[segment_num + 1],
                        clockwise=start_arc_clockwise  # we still wanna start this segment respecting the last corner
                    ))
                    last_arc_clockwise = start_arc_clockwise
                    print(f"    > {gcodes[-1].to_str()}")    
                
                elif start_arc_clockwise != next_corner_clockwise:
                    print(f"    > we'll do a double half arc to flip our curl into the upcoming corner's curl")
                    # we want to end this segment with a curl matching the corner we're entering. If e.g. the last arc
                    # was CW and we want to end this segment CW, then we'll need to do two half arcs.
                    gcodes.extend(self._two_half_arcs(
                        start=self.map_path[segment_num],
                        end=self.map_path[segment_num + 1],
                        first_arc_clockwise=start_arc_clockwise
                    ))
                    last_arc_clockwise = not start_arc_clockwise  # the second arc is curled opposite the first
                    print(f"    > {gcodes[-2].to_str()}, {gcodes[-1].to_str()}")    

                # Record state for next segment
                last_segment_corner = True
        
        print("final segment!")
        # Final segment! We don't care about preparing an upcoming corner (assuming we'll stop), so this can just be a full arc:
        # TODO should we worry about making these paths play nicely with one another? IDK
        gcodes.append(self._full_arc(
            start=self.map_path[-2],
            end=self.map_path[-1],
            clockwise=last_arc_clockwise if last_segment_corner else not last_arc_clockwise  # we still care about this tho
            ))

        return gcodes

    @staticmethod
    def _segment_direction(start: Node, end: Node) -> MapVector:
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

    def _full_arc(self, start: Node, end: Node, clockwise: bool) -> ArcMove:
        dir_vec = self._segment_direction(start, end)

        i, j = self._arc_center_offsets(direction=dir_vec, clockwise=clockwise)

        return ArcMove(
            x_mm=end[0] * self.map_config.map_grid_spacing_mm + self.map_config.map_x_offset,
            y_mm=end[1] * self.map_config.map_grid_spacing_mm + self.map_config.map_y_offset,
            i_mm= i * self.map_config.map_grid_spacing_mm,
            j_mm = j * self.map_config.map_grid_spacing_mm,
            clockwise=clockwise,
            speed_mm_s=self.speed_mm_s
        )
    
    def _two_half_arcs(self, start: Node, end: Node, first_arc_clockwise: bool) -> Tuple[ArcMove, ArcMove]:
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


if __name__ == "__main__":
    squiggle = SimpleSquigglePath(
        map_path=[
            (0, 0), (0, 1), (0, 2), (0, 3),
            (0, 4), (1, 4), (2, 4), (3, 4),
            (4, 4), (4, 3), (4, 2), (4, 1),
            (4, 0), (3, 0), (2, 0), (1, 0),
            (1, 1), (1, 2), (2, 2), (3, 2), (3, 3),
            (3, 4), (4, 4),
        ],
        map_config=MapConfig(10., 0., 0.),
        speed_mm_s=10000
    )
    # Points:
    # 3 4 5
    # 2 7 6
    # 1 8 B C
    # 0 9 A

    gcodes = squiggle.to_g_code()
    for i, gcode in zip(range(len(gcodes)), gcodes):
        #print(f"{i+1}: {gcode.to_str()}")
        print(f"{gcode.to_str()}")  # for g-code plotter at https://ncviewer.com/