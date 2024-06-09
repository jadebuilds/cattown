# custommap.py
# 
# Definition, load from file, and basic operations on our custom map type
# (a numpy array representing a grid of tiles on the front surface of the toy).
# 
# Author: Zoda

import numpy as np
from typing import Tuple
from dataclasses import dataclass

# Map values (not using an Enum for the moment because they're so clunky in Python)
EMPTY = 0
IMPASSABLE_TO_TOY = 1
IMPASSABLE_TO_CARRIAGE = 2
MOUSE_HOUSE_ENTRANCE = 3
MOUSE_HOUSE_DESTINATION = 4


@dataclass
class MapConfig:
    map_grid_spacing_mm: float  # For conversion between map locations (Nodes, int) and physical locations (Points, float)
    map_x_offset: float  # I think we'll probably need this to calibrate against the physical frame
    map_y_offset: float  # ""


OPEN_SAUCE_MAP_CONFIG = MapConfig(50.0, 0.0, 0.0)  # using a 50 mm spacing


def initialize_map(width_in: int, height_in: int) -> np.ndarray:
    # Create a 2D numpy array full of 0s
    grid = np.zeros((width_in, height_in), dtype=int)
    return grid

def add_obstacle(grid: np.ndarray, center: Tuple[int, int], v_padding: int, h_padding: int) -> np.ndarray:
    r, c = center
    grid[r, c] = 1

    for i in range(r - v_padding, r + v_padding + 1):
        for j in range(c - h_padding, c + h_padding + 1):
            if 0 <= i < grid.shape[0] and 0 <= j < grid.shape[1]:
                grid[i, j] = 1

    return grid

def generate_example() -> np.ndarray:
    # Building a map for a 1ft by 1ft wall, each grid if 1inch.
    inch_to_meter = 0.0254
    grid = initialize_map(12, 12)
    grid = add_obstacle(grid, (3, 3), 1, 1)  # Expecting a square around (3, 3)
    grid = add_obstacle(grid, (10, 10), 0, 0)  # Expecting a single dot at (10, 10)
    
    # Display the grid
    print("The map you have manifested")
    print(grid)
    print()
    
    return grid

def load_from_file(csv_filepath: str) -> np.ndarray:
    """
    Load from a CSV download. Expecting to use the Google Sheet map here:
    
    https://docs.google.com/spreadsheets/d/1h3TzB2h-GPvKF6A5ktIeTxZr08u3RLS3S5u_wHjHqy4/edit#gid=0
    """
    map = np.genfromtxt(csv_filepath, delimiter=',')  # type: np.ndarray
    return np.nan_to_num(map)


def node_is_passable(node_value: int) -> bool:
    return (
        (node_value != IMPASSABLE_TO_TOY) and
        (node_value != IMPASSABLE_TO_CARRIAGE)
    )

