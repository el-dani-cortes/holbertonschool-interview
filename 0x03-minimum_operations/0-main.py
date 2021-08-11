#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 4
print("Min # of o|perations to reach {} char: {}".format(n, minOperations(n)))

n = 49
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
