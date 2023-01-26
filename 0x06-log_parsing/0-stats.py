#!/usr/bin/python3
"""Script to reads stdin and computes metrics"""


import sys


stdinput = sys.stdin
status_code = ["200", "301", "400", "401", "403", "404", "405", "500"]
status_dict = {}
final_size = 0


def to_print():
    """function to print in format"""
    print("File size: {}".format(final_size))
    for i in status_code:
        if i in status_dict:
            print("{}: {}".format(i, status_dict[i]))


if __name__ == "__main__":
    """Prints statics from the begenin"""

    try:
        for idx, line in enumerate(stdinput):
            line = line.replace("-", " ", 1)
            line = line.replace("  ", "")
            data = line.split(" ")
            try:
                ip = data[0]
                date = data[1].replace("[", "") + " " + data[2].replace("]", "")
                method_str = data[3] + " " + data[4] + " " + data[5]
                status = data[6]
                file_size = int(data[7])

                if method_str != "\"GET /projects/260 HTTP/1.1\"":
                    continue

                if status in status_dict:
                    status_dict[status] += 1
                else:
                    status_dict[status] = 1

                final_size += file_size

                if idx != 0 and (idx + 1) % 10 == 0:
                    to_print()
            except Exception as e:
                pass
        to_print()
    except KeyboardInterrupt:
        to_print()
