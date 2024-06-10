# mice.py
# 
# Code for interfacing with mouse houses: representing state and switching mice.
# 
# Author: Jade

from dataclasses import dataclass
from typing import List, Optional

from .motion.gcodes import GCode, LinearMove, UseAbsoluteCoordinates, UseRelativeCoordinates
from .custommap import MapConfig, to_coordinates, Node
from .motion import MotionCommand

class MouseHouse:
    """
    """
    def __init__(self,
                 map_coords: Node,  # (X, Y) position of the mouse house entrance, in map coordinates (position on the 50 mm grid)
                 occupied: Optional[bool] = None,
                 ) -> None:
        
        self.map_coords = map_coords
        self.occupied = occupied  # I think we'll probably want to set/get this from CLI. TODO should we add explicit accessors?
    

class PickUpMouse(MotionCommand):
    """
    Motion sequence to pick up a mouse.

    Assumes all mouse houses are built exactly the same according to the Open Sauce design.
    """

    def __init__(self, mouse_house: MouseHouse, map_config: MapConfig) -> None:
        self.mouse_house = mouse_house
        self.map_config = map_config
    
    def to_g_code(self) -> List[GCode]:
        # We'll start out 
        just_below_sleeping_mouse = to_coordinates((
            self.mouse_house.map_coords[0] + 2,  # mouse sleeps two units to the right
            self.mouse_house.map_coords[1] - 1,  # 1 unit under the entrance
        ), self.map_config)

        return [
            # very rectangular
            # TODO tune me!!
            UseAbsoluteCoordinates(),
            LinearMove(just_below_sleeping_mouse.x_mm, just_below_sleeping_mouse.y_mm, 500),
            UseRelativeCoordinates(),
            LinearMove(0, 55.0, 300.0),  # slow transit up to pick up mouse...
            LinearMove(-25.0, 0.0, 200),  # ... a little to the left, in case the mouse is there...
            LinearMove(50.0, 0.0, 200),  # ... a little to the right, in case the mouse is there...
            LinearMove(-15.0, 0.0, 200), # ... and back to the center.
            LinearMove(0.0, 80.0, 500),  # now zip up to the center of the inner door,
            LinearMove(-100.0, 0.0, 500.0),  # left to exit through inner door,
            LinearMove(0.0, -80.0, 500),  # down toward the outer door,
            LinearMove(0.0, -40.0, 200),  # and poke your head out the door a little slowly, see what's goin on.
            UseAbsoluteCoordinates(),  # clean up!
        ]

class DropOffMouse(MotionCommand):

    def __init__(self, mouse_house: MouseHouse, map_config: MapConfig) -> None:
        self.mouse_house = mouse_house
        self.map_config = map_config
    
    def to_g_code(self) -> List[GCode]:
        # We'll start out 
        just_below_house_entrance = to_coordinates((
            self.mouse_house.map_coords[0],
            self.mouse_house.map_coords[1] - 1,  # 1 unit under the entrance
        ), self.map_config)

        # TODO we should mark the house occupied when this actually gets executed,
        # but not beforehand... how does that work?

        return [
            # very rectangular
            # TODO tune me!!
            UseAbsoluteCoordinates(),
            LinearMove(just_below_house_entrance.x_mm, just_below_house_entrance.y_mm, 500),
            UseRelativeCoordinates(),
            LinearMove(0, 135.0, 500.0),  # quick run to get into the house
            # TODO arcs? idk if needed
            LinearMove(100.0, 0.0, 500.0),  # right to enter through inner door
            LinearMove(0.0, -70.0, 500),  # approach the bottom fast...
            LinearMove(0.0, -65.0, 100),  # ... then very slow to drop the mouse against the bottom.
            UseAbsoluteCoordinates(),  # clean up!
        ]
