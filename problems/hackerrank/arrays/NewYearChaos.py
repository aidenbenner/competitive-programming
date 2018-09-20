#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    count = 0
    bribes = {}
    sorted = False
    while not sorted:
        sorted = True
        for i in range(len(q)):
            if i == len(q) - 1:
                continue
            if q[i] == i + 1:
                continue
            if q[i] - (i + 1) > 2:
                print("Too chaotic")
                return
            elif q[i+1] < q[i]:
                sorted = False
                tmp = q[i]
                q[i] = q[i + 1]
                q[i + 1] = tmp
                count += 1
            # print(q)
    print(count)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
