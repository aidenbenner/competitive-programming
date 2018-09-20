#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumSwaps function below.
def minimumSwaps(arr):
    s = sorted(arr)
    mp = {}
    i = 0
    for x in s:
        mp[x] = i
        i += 1

    i = 0
    while i < len(arr):
        arr[i] = mp[arr[i]]
        i += 1
    # print(arr)

    sp = 0
    i = 0
    while i < len(arr):
        if i == arr[i]:
            i += 1
            continue
        # swap ith position with arr[i]th
        a = i
        b = arr[i]

        tmp = arr[a]
        arr[a] = arr[b]
        arr[b] = tmp
        sp += 1
        # print(arr)

    return sp

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    res = minimumSwaps(arr)

    fptr.write(str(res) + '\n')

    fptr.close()

