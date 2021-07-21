#!/usr/bin/python3
"""Lockboxes task"""


def canUnlockAll(boxes):
    """Method that determines if all the boxes can be opened"""
    total_boxes = len(boxes)
    key_found_box_0 = False
    for number in boxes[0]:
        if number >= 1 and number <= total_boxes:
            key_found_box_0 = True
    if key_found_box_0 is True:
        unlock_result = []
        for index in range(1, total_boxes):
            unlock = False
            for i in range(0, total_boxes):
                if index != i and index in boxes[i]:
                    unlock_result.append("unlock")
                    unlock = True
                    continue
            if unlock is False:
                unlock_result.append("lock")
            else:
                continue
        if "lock" not in unlock_result:
            return True
    return False
