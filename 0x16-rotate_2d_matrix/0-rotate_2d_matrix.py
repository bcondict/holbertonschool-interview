#!/usr/bin/python3
"""rotate 2d matrix module"""


def rotate_2d_matrix(matrix):
    """rotate 2d matrix"""
    matrix.reverse()
    for i in range(len(matrix)):
        for j in range(i):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
