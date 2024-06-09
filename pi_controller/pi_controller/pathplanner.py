# pathplanner.py
#
# Path planning along the map using A* search.
# 
# Author: Zoda


from typing import List, Dict, Tuple, Optional
import numpy as np
import random
from queue import PriorityQueue

from .custommap import load_from_file, node_is_passable, add_obstacle

Node = Tuple[int, int]
Path = List[Node]

class PathFinder:
    def __init__(self, map_file: str):
        self.grid = load_from_file(map_file)
        self.map_width, self.map_height = self.grid.shape

    def redraw_path(self, start: Node, cat_location: Node) -> Optional[Path]:
        self.grid = add_obstacle(self.grid, cat_location, 2, 2)
        goal = self._get_random_passable_node()
        print(goal)
        return self.go_to_coords(start, goal)

    def go_to_coords(self, start: Node, goal: Node) -> Optional[Path]:
        return self._a_star(start, goal)

    def _get_neighbors(self, node: Node) -> List[Node]:
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        return [
            (node[0] + dx, node[1] + dy)
            for dx, dy in directions
            if 0 <= node[0] + dx < self.map_width
            and 0 <= node[1] + dy < self.map_height
            and node_is_passable(self.grid[node[0] + dx, node[1] + dy])
        ]

    def _a_star(self, start: Node, goal: Node) -> Optional[Path]:
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

    def _heuristic(self, node: Node, goal: Node) -> int:
        return abs(node[0] - goal[0]) + abs(node[1] - goal[1])

    def _reconstruct_path(self, came_from: Dict[Node, Node], current: Node) -> Path:
        path = []
        while current in came_from:
            path.append(current)
            current = came_from[current]
        path.append(current)
        return path[::-1]

    def _get_random_passable_node(self) -> Node:
        while True:
            node = (random.randint(0, self.map_width - 1), random.randint(0, self.map_height - 1))
            if self.grid[node] == 0:
                return node

if __name__ == '__main__':
    path_finder = PathFinder('map.csv')
    start = (0, 0)
    goal = (11, 11)
    path_finder.grid[start[0], start[1]] = 7
    path_finder.grid[goal[0], goal[1]] = 8
    path = path_finder.go_to_coords(start, goal)
    print("The map you have traversed!")
    print(path_finder.grid)
