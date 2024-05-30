from typing import List, Dict, Tuple, Optional
from queue import PriorityQueue
from custommap import start

def go_to_coords(grid: List[List[int]], start: Tuple[int, int], goal: Tuple[int, int]) -> List[Tuple[int, int]]:
    a_star(grid, start, goal)
    return

def get_neighbors(grid: List[List[int]], node: Tuple[int, int]):
    neighbors = []
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    for direction in directions:
        neighbor_x = node[0] + direction[0]
        neighbor_y = node[1] + direction[1]

        if 0 <= neighbor_x < len(grid) and 0 <= neighbor_y < len(grid[0]):
            if grid[neighbor_x][neighbor_y] != "1":  # Check if it's not an obstacle
                neighbors.append((neighbor_x, neighbor_y))

    return neighbors

def a_star(grid: List[List[int]], start: Tuple[int, int], goal: Tuple[int, int]) -> List[Tuple[int, int]]:
    open_list = PriorityQueue()
    open_list.put((0, start))
    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic(start, goal)}

    while not open_list.empty():
        _, current = open_list.get()

        if current == goal:
            return reconstruct_path(came_from, current)

        for neighbor in get_neighbors(grid, current):
            tentative_g_score = g_score[current] + 1  # assuming uniform cost

            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)
                open_list.put((f_score[neighbor], neighbor))

    return None  # No path found

def heuristic(node:Tuple[int, int], goal: Tuple[int, int]) -> List[Tuple[int, int]]:
    return abs(node[0] - goal[0]) + abs(node[1] - goal[1])  # Manhattan distance

def reconstruct_path(came_from: Tuple[int, int], current: Tuple[int, int]) -> List[Tuple[int, int]]:
    path = []
    while current in came_from:
        path.append(current)
        current = came_from[current]
    path.append(current)  # Add start node
    mark_path_on_grid(grid, path[::-1])
    return path[::-1]  # Return reversed path


def mark_path_on_grid(grid: List[Tuple[int, int]], path: List[Tuple[int, int]]):
    for node in path:
        grid[node[0]][node[1]] = 2
    return grid

if __name__ == '__main__':
    grid = start()
    
    start = (0, 0)
    goal = (11, 11)
    grid[start[0]][start[1]] = 'S'
    grid[goal[0]][goal[1]] = 'G'
    
    go_to_coords(grid, start, goal)

    print("The map you have traversed!")
    for row in grid:
        print(' '.join(map(str, row)))
    print()

    