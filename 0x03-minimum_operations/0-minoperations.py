#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to
    result in exactly n H characters in the file
    """
    if n <= 1:
        return 0

    num_operations = 0
    while (n > 1):
        for divisor in range(2, n + 1):
            if (n % divisor == 0):
                num_operations += divisor
                n = n // divisor
                break
    return num_operations
