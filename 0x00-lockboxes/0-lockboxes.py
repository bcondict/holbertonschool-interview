#!/usr/bin/python3
""" This module contains a function that checks if lockboxes can be opened by the keys inside them"""

def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""
    unlocked = [0]

    for index, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != index:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
