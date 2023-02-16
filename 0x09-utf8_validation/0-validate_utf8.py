#!/usr/bin/python3
"""
Defines a method that determines if a given data set
represents valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Determines if a given data set represents valid UTF-8 encoding

    parameters:
        data [list of ints]:
            each integer represents 1 byte of data
            data set can contain multiple characters
            each character in UTF-8 can be 1 to 4 bytes long

    returns:
        True if data is valid UTF-8 encoding, False otherwise
    """
    valid = 0
    for value in data:
        byte = value & 255
        if valid:
            if byte >> 6 != 2:
                return False
            valid -= 1
            continue
        while (1 << abs(7 - valid)) & byte:
            valid += 1
        if valid == 1 or valid > 4:
            return False
        valid = max(valid - 1, 0)
    return valid == 0
