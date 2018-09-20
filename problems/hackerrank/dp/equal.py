#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the equal function below.
def equal(arr):
    m = min(arr)
    starts = [m - i for i in range(0,6)]

    out = minimize(arr, m)
    for s in starts:
        out = min(out, minimize(arr, s))
    return out

def minimize(arr, x):
    total_moves = 0
    for a in arr:
        moves = (a - x) // 5
        remain = (a - x) % 5
        moves += remain // 2
        moves += remain % 2
        total_moves += moves
    return total_moves

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        result = equal(arr)

        fptr.write(str(result) + '\n')

    fptr.close()
