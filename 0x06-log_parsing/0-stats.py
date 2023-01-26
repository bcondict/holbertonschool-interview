#!/usr/bin/python3
"""Script to reads stdin and computes metrics"""


import sys
import ipaddress
from dateutil.parser import parse


def is_valid_ip(ip):
    """Check if an IP is a valid IP"""
    try:
        ipaddress.IPv4Address(ip)
        return True
    except ValueError:
        return False


def validator():
    """Prints statics from the begenin"""
    stdinput = sys.stdin
    status_code = [200, 301,  400, 401, 403, 404, 405, 500]
    status_dict = {}
    final_size = 0

    try:
        for idx, line in enumerate(stdinput):
            data = line.split(" ")
            ip = data[0]
            date = data[2].replace("[", "") + " " + data[3].replace("]", "")
            method_str = data[4] + " " + data[5] + " " + data[6]
            status = int(data[7])
            file_size = int(data[8])

            try:
                parse(date)
                if not is_valid_ip(ip):
                    print("0")
                    break
                if method_str != "\"GET /projects/260 HTTP/1.1\"":
                    print("1")
                    break
                if status not in status_code:
                    print("2")
                    break

                if status in status_dict:
                    status_dict[status] += 1
                else:
                    status_dict[status] = 1

                final_size += file_size

                if idx != 0 and (idx + 1) % 10 == 0:
                    print("File size: {}".format(final_size))
                    for i in status_code:
                        if i in status_dict:
                            print("{}: {}".format(i, status_dict[i]))
            except Exception:
                break
    except KeyboardInterrupt:
        print("File size: {}".format(final_size))
        for i in status_code:
            if i in status_dict:
                print("{}: {}".format(i, status_dict[i]))


validator()
