#!/usr/bin/python3
import sys
import re


def print_stats(file_size_total, status_code, order_codes):
    """Print the stats"""
    print("File size: {}".format(file_size_total))
    for code in order_codes:
        print("{}: {}".format(code, status_code[code]))


def get_data_from_stdin():
    """Get data form standard input"""
    log_pattern = r'\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\b - \[[0-9]*-[0-9]*-[0-9]* [0-9]*:[0-9]*:[0-9]*\.[0-9]*\] "GET \/projects\/260 HTTP\/1\.1" [0-9]* [0-9]*$'
    status_code = {"200": 0, "301": 0, "400": 0,
                   "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}
    order_codes = list(status_code.keys())
    file_size_total = 0
    line_counts = 1
    try:
        for line in sys.stdin:
            check_pattern = re.search(log_pattern, line)
            if check_pattern:
                data = re.findall(r' (\d{3})\s(\d*)$', line)
                if data[0][0] in status_code.keys():
                    line_counts += 1
                    status_code[data[0][0]] += 1
                    file_size_total += int(data[0][1])
                else:
                    continue
                if line_counts > 10:
                    print_stats(file_size_total, status_code, order_codes)
                    line_counts = 1
    except KeyboardInterrupt:
        print_stats(file_size_total, status_code, order_codes)


if __name__ == "__main__":
    get_data_from_stdin()
