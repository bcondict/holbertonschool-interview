#!/usr/bin/python3
"""
    0-pascal_triangle
"""


def pascal_triangle(n):
    """
        pascal triangle - returns a list of lists of integers
        representing the Pascal’s triangle of n
    """
    pascalTriangle = list()
    row = list()

    # in case of empty triangle or negative number
    # return empty list
    if (n <= 0):
        return pascalTriangle

    for idx in range(n):
        # first row is always 1
        if (idx == 0):
            pascalTriangle.append([1])
            continue

        # reset row
        row = list()

        # for the rest of the rows
        for j in range(idx + 1):
            # first and last element of each row
            # are always 1
            if (j == 0) or (j == idx):
                row.append(1)
                continue

            # middle elements are the sum of the
            # two elements above
            row.append(
                pascalTriangle[idx - 1][j - 1] +
                pascalTriangle[idx - 1][j]
            )

        # append row to triangle
        pascalTriangle.append(row)
    return (pascalTriangle)
