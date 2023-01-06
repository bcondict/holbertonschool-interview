#!/usr/bin/python3
"""
    given a number and a character
    print char amount of times than number indicates in the minimum operations
"""
import math


def is_prime(num):
    """check if a number is prime"""
    for n in range(2, num):
        if num % n == 0:
            return False
    return True


def minOperations(n):
    """
        Method: Given a number n calculates the fewest number of operations
        needed to result in exactly n amount of characters in the file.
    """
    if math.isinf(n) or n < 1:
        return 0

    my_num = 1
    adition = 1

    if is_prime(n):
        return n

    num_operations = 1
    for index in range(n):
        if (my_num == n):
            return num_operations
        if (my_num != 1 and n % my_num == 0):
            num_operations += 1
            adition = my_num
        num_operations += 1
        my_num += adition
    return num_operations
