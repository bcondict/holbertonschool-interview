#!/usr/bin/python3
"""Prime Game"""


def prime_numbers(start_num, end_num):
    """Return list of int of prime numbers"""
    list_prime_numbers = []
    for number in range(start_num, end_num + 1):
        is_prime = True
        for counter in range(2, number):
            value = number % counter
            if value == 0:
                is_prime = False
                break
        if is_prime:
            list_prime_numbers.append(number)
    return list_prime_numbers


def isWinner(x, nums):
    """
        args:
            x is the number of rounds
            nums is an array of integers
        return:
            name of the player that won the most rounds
            None if a winner cannot be determinated
    """
    winner = None
    scoreMaria = 0
    scoreBen = 0
    new_nums = []

    for _round in range(x):
        if (nums[_round] == 1):
            scoreBen += 1
            continue
        if (nums[_round] == 2):
            scoreMaria += 1
            continue
        if (nums[_round] > 2):
            new_nums = prime_numbers(2, nums[_round])
            if (len(new_nums) % 2 == 0):
                scoreBen += 1
            else:
                scoreMaria += 1

    if (scoreMaria > scoreBen):
        winner = "Maria"
    if (scoreMaria < scoreBen):
        winner = "Ben"

    return winner
