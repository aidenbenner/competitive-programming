import math
import itertools

N = int(input())

cords = []
s = input().split(" ")
for y in s:
    cords.append([int(y)])
s = input().split(" ")
i = 0
for x in s:
    cords[i].append(int(x))
    i += 1

cords = sorted(cords, key= lambda a: a[0])

def orderedOb(a,b,c,d):
    if ordTri(a,b,c) and ordTri(b,c,d) and ordTri(d,a,b) and ordTri(c,d,a):
        da = dist(a,b)
        db = dist(b,c)
        dc = dist(c,d)
        dd = dist(d,a)

        if da == db and db == dc and dc == dd:
            return False
        return True
    return False

    da = dist(a,b)
    db = dist(a,c)
    dc = dist(a,d)
    dd = dist(a,c)

    # 2 rightmost are first
    if a[0] - b[0] != c[0] - d[0]:
        return False
    if a[1] - b[1] != c[1] - d[1]:
        return False
    return True


def isOblong(a, b, c, d):
    mp = {}
    for x in itertools.permutations([a,b,c,d], 2):
        if dist(x[0], x[1]) == 0:
            return False

    for x in itertools.permutations([a,b,c,d], 4):
        if orderedOb(x[0], x[1], x[2], x[3]):
            return True
    return False

def dist(a,b):
    dx = a[1] - b[1]
    dy = a[0] - b[0]
    return dx * dx + dy * dy


def ordTri(a,b,c):
    A = dist(a,b)
    B = dist(b,c)
    C = dist(a,c)

    if A + B == C:
        return True

def isTri(a,b,c):
    A = dist(a,b)
    B = dist(a,c)
    C = dist(b,c)
    if A == 0 or B == 0 or C == 0:
        return False

    if A + B == C:
        return True
    if A + C  == B:
        return True
    if B + C== A:
        return True
    return False

count = 0
for c in itertools.combinations(cords, 4):
    if isOblong(c[0], c[1], c[2], c[3]):
        cpy = list(c[::])
        diff = []
        for a in cords:
            if a in cpy:
                cpy.remove(a)
            else:
                diff.append(a)

        for t in itertools.combinations(diff, 3):
            if isTri(t[0], t[1], t[2]):
                count += 1

print(count)




