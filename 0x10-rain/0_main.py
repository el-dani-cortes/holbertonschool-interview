#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":

    walls = "Cheese"
    print(rain(walls))

    walls = []
    print(rain(walls))

    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))

    walls = [4, 0, 3, 0, 2, 0, 1, 0]
    print(rain(walls))

    walls = [0, 1, 0, 2, 0, 3, 0, 4, 0, 4, 0, 3, 0, 2, 0, 1, 0]
    print(rain(walls))

    walls = [2, 0, 1, 0, 2]
    print(rain(walls))

    walls = [0, 2, 0, 1, 0, 2, 0]
    print(rain(walls))

    walls = [0, 2, 0, 1, 0, 3, 0]
    print(rain(walls))

    walls = [0, 2, 0, 0, 0, 1]
    print(rain(walls))

    walls = [1, 0, 0, 3, 0, 2, 0, 1, 0, 3, 0, 1]
    print(rain(walls))

    walls = [0, 0, 2, 1, 3]
    print(rain(walls))
