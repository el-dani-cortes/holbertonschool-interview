#!/usr/bin/python3
"""
Print stats from server's logs
"""
import re
import sys


def print_stats(file_size_total, status_code, order_codes):
    """Print the stats"""
    print("File size: {}".format(file_size_total))
    for code in order_codes:
        if status_code[code] != 0:
            print("{}: {}".format(code, status_code[code]))


def get_data_from_stdin():
    """Get data form standard input"""
    status_code = {"200": 0, "301": 0, "400": 0,
                   "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
    order_codes = ["200", "301", "400", "401", "403", "404", "405", "500"]
    file_size_total = 0
    line_counts = 0
    try:
        while True:
            try:
                line = input()
                data = re.findall(r' (\d{3})\s(\d*)$', line)
                if data and data[0][0] in status_code.keys():
                    line_counts += 1
                    status_code[data[0][0]] += 1
                    file_size_total += int(data[0][1])
                else:
                    continue
                if line_counts >= 10:
                    print_stats(file_size_total, status_code, order_codes)
                    line_counts = 0
            except EOFError:
                if line_counts < 10:
                    print_stats(file_size_total, status_code, order_codes)
                break
    except KeyboardInterrupt:
        print_stats(file_size_total, status_code, order_codes)


if __name__ == "__main__":
    get_data_from_stdin()
