from typing import List, Dict, Tuple, Optional
from queue import PriorityQueue
import numpy as np
from typing import Tuple, List, Optional
from queue import PriorityQueue
from .custommap import load_from_file, node_is_passable

Node = Tuple[int, int]  # indices on the array (will map to real coordinates later)
Path = List[Node]  # list of nodes to traverse (will turn into motion path later)

def go_to_coords(grid: np.ndarray, start: Node, goal: Node) -> Optional[Path]:
    return _a_star(grid, start, goal)

def _get_neighbors(grid: np.ndarray, node: Node) -> List[Node]:
    neighbors = []
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    for direction in directions:
        neighbor_x = node[0] + direction[0]
        neighbor_y = node[1] + direction[1]

        if 0 <= neighbor_x < grid.shape[0] and 0 <= neighbor_y < grid.shape[1]:
            if node_is_passable(grid[neighbor_x, neighbor_y]):  # Check if it's not an obstacle
                neighbors.append((neighbor_x, neighbor_y))

    return neighbors

def _a_star(grid: np.ndarray, start: Node, goal: Node) -> Optional[Path]:
    open_list = PriorityQueue()
    open_list.put((0, start))
    came_from = {}
    g_score = {start: 0}
    f_score = {start: _heuristic(start, goal)}

    while not open_list.empty():
        _, current = open_list.get()

        if current == goal:
            return _reconstruct_path(came_from, current)

        for neighbor in _get_neighbors(grid, current):
            tentative_g_score = g_score[current] + 1  # assuming uniform cost

            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + _heuristic(neighbor, goal)
                open_list.put((f_score[neighbor], neighbor))

    return None  # No path found

def _heuristic(node: Node, goal: Node) -> int:
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])  # Manhattan distance

def _reconstruct_path(came_from: dict, current: Node) -> Path:
    path = []
    while current in came_from:
        path.append(current)
        current = came_from[current]
    path.append(current)  # Add start node
    return path[::-1]  # Return reversed path


if __name__ == '__main__':
    grid = load_from_file('map.csv')
    
    start = (0, 0)
    goal = (11, 11)
    grid[start[0], start[1]] = 7
    grid[goal[0], goal[1]] = 8
    
    go_to_coords(grid, start, goal)

    print("The map you have traversed!")
    print(grid)
    