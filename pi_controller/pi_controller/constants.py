from dataclasses import dataclass
from typing import Tuple, List

@dataclass
class MapConfig:
    map_grid_spacing_mm: float  # For conversion between map locations (Tiles, int) and physical locations (Points, float)
    map_x_offset: float  # For calibration against the physical frame -- because 0, 0 for the drive system
    map_y_offset: float  #     is inset from the left bottom of the board by the frame and mounting brackets.
    grid_size_x: int  # Size of the map. Assumed to fit within the board -- note that we don't currently
    grid_size_y: int  # do any size checking! Any tile is assumed to be all valid Points on the board

# Open Sauce map is here: https://docs.google.com/spreadsheets/d/1h3TzB2h-GPvKF6A5ktIeTxZr08u3RLS3S5u_wHjHqy4/edit#gid=1701643471
OPEN_SAUCE_MAP_CONFIG = MapConfig(
    map_grid_spacing_mm=50.0, # 100 mm slot grid, divided by two ("on the slot" vs. "between slots")
    map_x_offset=-137.0,  # Drive system "home" point is 137mm right and 53 mm up
    map_y_offset= -53.0,  # from the lower left corner of the board
    grid_size_x=47,  # 6 slots * 4 panels, time two minus one (note that when zero-indexed, as in the Google Sheet, it's 0:46)
    grid_size_y=21,  # 11 slots vertically per panel, times two minus one
)


# Map values (not using an Enum for the moment because they're so clunky in Python)
PASSABLE = 0
INACCESSIBLE = 1
IMPASSABLE = 2
MOUSE_HOUSE_ENTRANCE = 3

# type wrapper for positions on the grid. 
# TODO syntactic sugar for element-wise add/subtract??
# Note that equality comparison already works
Tile = Tuple[int, int] 
Path = List[Tile]

@dataclass
class Point:  # A physical location on the board, measured in millimeters.
    x_mm: float
    y_mm: float
