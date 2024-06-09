from dataclasses import dataclass
from typing import Tuple, List

@dataclass
class MapConfig:
    map_grid_spacing_mm: float  # For conversion between map locations (Nodes, int) and physical locations (Points, float)
    map_x_offset: float  # I think we'll probably need this to calibrate against the physical frame
    map_y_offset: float  # ""


OPEN_SAUCE_MAP_CONFIG = MapConfig(50.0, 0.0, 0.0)  # using a 50 mm spacing


# Map values (not using an Enum for the moment because they're so clunky in Python)
PASSABLE = 0
INACCESSIBLE = 1
IMPASSABLE = 2
MOUSE_HOUSE_ENTRANCE = 3

# type wrapper for positions on the grid. 
# TODO syntactic sugar for element-wise add/subtract??
Node = Tuple[int, int] 
Path = List[Node]
