from typing import List, Tuple

def initialize_map(width_in: int, hight_in: int) -> List[List[int]]:
    rows = width_in
    cols = hight_in
    # 2D matrix full of 0s
    grid = [[0 for _ in range(cols)] for _ in range(rows)]
    return grid

def add_obstacle(grid: List[List[int]], center: Tuple[int, int], v_padding: int, h_padding: int) -> List[List[int]]:
    r, c = center
    grid[r][c] = 1

    for i in range(r - v_padding, r + v_padding + 1):
        for j in range(c - h_padding, c + h_padding + 1):
            if 0 <= i < len(grid) and 0 <= j < len(grid[0]):
                grid[i][j] = 1

    return grid


def start() -> List[List[int]]:
    # Building a map for a 1ft by 1ft wall, each grid if 1inch.
    inch_to_meter = 0.0254
    grid = initialize_map(12, 12)
    grid = add_obstacle(grid, (3,3), 1, 1) # Expecting a square around (3, 3)
    grid = add_obstacle(grid, (10,10), 0, 0) # Expecting a single dot at (10, 10)
    
    # Display the grid
    print("The map you have manifested")
    for row in grid:
        print(' '.join(map(str, row)))
    print()
    
    return grid


