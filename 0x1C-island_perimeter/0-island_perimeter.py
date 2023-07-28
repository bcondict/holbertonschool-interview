#!/usr/bin/python3
"""
0-island_perimeter
"""


def island_perimeter(grid):
    """
        Calulcate the perimeter of the island described in grid

        Args:
            grid ([[int]]): is a list of list of integers

        Return: perimeter of the island described in grid
    """
    perimeter = 0
    for row_idx, row in enumerate(grid):
    # go through each row in the grid
        for col_idx, col in enumerate(row):
        # go through each column in the row
            if col == 1:
            # if the current cell is land, add 4 to the perimeter
                perimeter += 4
                if row[col_idx - 1] > 0:
                # if the cell to the left is land, subtract 2 from the
                # perimeter because the left cell's right side is touching
                # the current cell's left side
                    perimeter -= 2
                if grid[row_idx - 1][col_idx] > 0:
                # if the cell above is land, subtract 2 from the perimeter
                # because the above cell's bottom side is touching
                # the current cell's top side
                    perimeter -= 2

    return perimeter
