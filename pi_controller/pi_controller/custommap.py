# custommap.py
# 
# Definition, load from file, and basic operations on our custom map type
# (a numpy array representing a grid of tiles on the front surface of the toy).
# 
# Author: Zoda

import numpy as np
from typing import Tuple

from .constants import Tile, Path, Point, MapConfig, PASSABLE, INACCESSIBLE, IMPASSABLE, MOUSE_HOUSE_ENTRANCE

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


def tile_is_passable(tile_value: int) -> bool:
    return (
        (tile_value != INACCESSIBLE) and
        (tile_value != IMPASSABLE)
    )

def to_coordinates(tile: Tile, map_config: MapConfig) -> Point:
    """
    Convert a grid tile on the map (X, Y as integer coordinates) to a physical
    position on the board (X, Y in millimeters) using what we know about the size 
    and position of the map grid.

    This should be understood to yield the geometric center of the tile. For the 
    V5 Open Sauce prototype, tiles are placed so that they either have a slot directly
    in the center, or the center of the tile is exactly between two slots (this is 
    individually true in both X and Y).

    Not hard, just figured I'd wrap it so we don't have to do it over and over again!
    """
    coords = Point(
        x_mm=tile[0] * map_config.map_grid_spacing_mm + map_config.map_x_offset,
        y_mm=tile[1] * map_config.map_grid_spacing_mm + map_config.map_y_offset,
    )

    # Floor negative coordinates. This is a cheesy little workaround for the Open
    # Sauce prototype, the bottom-most addressable row of map tiles are juuuuuust under
    # 0 mm for the motion system and so I'm going to make them traversable anyway
    # and just trim up 3 mm. Shouldn't be noticeable to the user, keeps that addressable!
    if coords.x_mm < 0:
        coords.x_mm = 0
    if coords.y_mm < 0:
        coords.y_mm = 0

    return coords

def to_tile(point: Point, map_config: MapConfig) -> Tile:
    """
    Convert coordinates back to the nearest grid tile. 
    """

    tile = Tile(
        (point.x_mm - map_config.map_x_offset) / map_config.map_grid_spacing_mm,
        (point.y_mm - map_config.map_y_offset) / map_config.map_grid_spacing_mm
    )
    
    assert 0 <= tile[0] <= map_config.grid_size_x, f"X={tile[0]} (from point {point}) is not in bounds!"
    assert 0 <= tile[1] <= map_config.grid_size_y, f"Y={tile[1]} (from point {point}) is not in bounds!"

