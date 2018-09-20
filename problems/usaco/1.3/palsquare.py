"""
ID: aiden.b1
LANG: PYTHON3
TASK: palsquare
"""

def dig(x):
    if x < 10:
        return str(x)
    return chr(int(x - 10 + ord('A')))

def numToBase(x, b):
    print(x)
    out = ""
    while x != 0:
        out = dig(x % b) + out
        x /= b

def isPalin(s):
    rev = s[::-1]

    i=0
    while i < len(s):
        if rev[i] != s[i]:
            return False
        i += 1
    return True

print(numToBase(300, 20))
fin = open('palsquare.in', 'r')
fout = open('palsquare.out', 'w')



b = int(fin.readline().strip())


for x in range(1, 301):
    s = numToBase(x, b)
    square = numToBase(x * x, b)
    if isPalin(square):
        fout.write(s + " " + square)

