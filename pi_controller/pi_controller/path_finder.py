# pathfinder.py
#
# Path planning along the map using A* search.
# 
# Author: Zoda

import logging
import numpy as np
import random
from typing import List, Dict, Optional
from queue import PriorityQueue

from .constants import Tile, Path
from .custommap import load_from_file, tile_is_passable, add_obstacle

logger = logging.Logger(__name__)

class PathFinder:
    def __init__(self, map_file: str):
        self.grid = load_from_file(map_file)
        self.grid = np.transpose(self.grid)
        self.map_width, self.map_height = self.grid.shape

    def redraw_path(self, start: Tile, cat_location: Tile) -> Path:
        retries = 100
        path = None
        self.grid = add_obstacle(self.grid, cat_location, 2, 2)
        for i in range(retries):
            goal = self._get_random_passable_tile()
            path = self.go_to_coords(start, goal)
            if path: return path
        logger.error("Unable to generate a new path after {retries} retries")

    def redraw_path_if_necessary(
        self, 
        start: Tile, 
        cat_location: Tile, 
        path: List[Tile], 
        cat_closeness_threshhold: Optional[int],
        check_upcoming_tiles: Optional[int],
        minimum_path_len: Optional[int]
    ) -> Path:
        if len(path) < minimum_path_len:
            return self.redraw_path(start, cat_location)
        for tile in path[:check_upcoming_tiles]:
            dx_too_small = abs(tile[0] - cat_location[0]) <= cat_closeness_threshhold
            dy_too_small = abs(tile[1] - cat_location[1]) <= cat_closeness_threshhold
            cat_is_close = dx_too_small or dy_too_small 
            if cat_is_close:
                return self.redraw_path(start, cat_location)

    def go_to_coords(self, start: Tile, goal: Tile) -> Optional[Path]:
        logger.debug("start: ", start)
        logger.debug("goal: ", goal)
        logger.debug("Is goal passable? ", tile_is_passable(self.grid, goal))
        logger.debug("Is start passable? ", tile_is_passable(self.grid, start))
        logger.debug("Start value?", self.grid[start[0]][start[1]])
        logger.debug("Goal value?", self.grid[goal[0]][goal[1]])
        logger.debug("Grid shape?", self.grid.shape)
        return self._a_star(start, goal)

    def _get_neighbors(self, tile: Tile) -> List[Tile]:
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        return [
            (tile[0] + dx, tile[1] + dy)
            for dx, dy in directions
            if 0 <= tile[0] + dx < self.map_width
            and 0 <= tile[1] + dy < self.map_height
            and tile_is_passable(self.grid, (tile[0] + dx, tile[1] + dy))
        ]

    def _a_star(self, start: Tile, goal: Tile) -> Optional[Path]:
        open_set = PriorityQueue()
        open_set.put((0, start))
        came_from = {}
        g_score = {start: 0}
        f_score = {start: self._heuristic(start, goal)}

        while not open_set.empty():
            _, current = open_set.get()

            if current == goal:
                return self._reconstruct_path(came_from, current)

            for neighbor in self._get_neighbors(current):
                tentative_g_score = g_score[current] + 1

                if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g_score
                    f_score[neighbor] = tentative_g_score + self._heuristic(neighbor, goal)
                    open_set.put((f_score[neighbor], neighbor))

        return None

    def _heuristic(self, tile: Tile, goal: Tile) -> int:
        return abs(tile[0] - goal[0]) + abs(tile[1] - goal[1])

    def _reconstruct_path(self, came_from: Dict[Tile, Tile], current: Tile) -> Path:
        path = []
        while current in came_from:
            path.append(current)
            current = came_from[current]
        path.append(current)
        return path[::-1]

    def _get_random_passable_tile(self) -> Tile:
        while True:
            tile = (random.randint(0, self.map_width - 1), random.randint(0, self.map_height - 1))
            if self.grid[tile] == 0:
                return tile

if __name__ == '__main__':
    path_finder = PathFinder('map.csv')
    start = (0, 0)
    goal = (11, 11)
    path_finder.grid[start[0], start[1]] = 7
    path_finder.grid[goal[0], goal[1]] = 8
    path = path_finder.go_to_coords(start, goal)
    print("The map you have traversed!")
    print(path_finder.grid)
