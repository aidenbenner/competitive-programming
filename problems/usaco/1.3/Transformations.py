"""
ID: aiden.b1
LANG: PYTHON3
TASK: transform
"""
fin = open ('transform.in', 'r')
fout = open ('transform.out', 'w')

N = int(fin.readline())


a = []
for x in range(N):
    line = fin.readline().strip()
    a.append([])
    for c in line:
        a[-1].append(c)

b = []
for x in range(N):
    line = fin.readline().strip()
    b.append([])
    for c in line:
        b[-1].append(c)

def compare():
    i = 0
    while i < len(a):
        k = 0
        while k < len(a[0]):
            if a[i][k] != b[i][k]:
                return False
            k += 1
        i += 1
    return True

def reflectx():
    i = 0
    while i < len(a):
        a[i] = a[i][::-1]
        i += 1

def reflecty():
    i = 0
    while i <= len(a) / 2:
        k = 0
        while k < len(a):
            tmp = a[i][k]
            a[i][k] = a[-1-i][k]
            a[-1-i][k] = tmp
            k += 1
        i += 1

def transpose():
    i = 0
    swpd = {}
    while i < len(a):
        k = 0
        while k < len(a):
            if (i, k) in swpd or (k,i) in swpd:
                k += 1
                continue
            swpd[(i,k)] = True
            swpd[(k,i)] = True
            tmp = a[i][k]
            a[i][k] = a[k][i]
            a[k][i] = tmp
            # print(str(i) + " " + str(k) + " " + tmp, "")
            k += 1
        i += 1

def rotate():
    transpose()
    reflectx()

def p():
    for x in a:
        l = ""
        for y in x:
            l += y
        print(l)

rotate()
if compare():
    fout.writelines("1\n")
    quit()
rotate()
if compare():
    fout.writelines("2\n")
    quit()
rotate()
if compare():
    fout.writelines("3\n")
    quit()
rotate()
#reflecty()
if compare():
    fout.writelines("4\n")
    quit()
#reflecty()
reflectx()
if compare():
    fout.write("4\n")
    quit()
reflectx()


def check():
    for i in range(4):
        rotate()
        if compare():
            fout.writelines("5\n")
            quit()

reflectx()
check()
reflecty()
check()
reflectx()
check()
reflectx()

if compare():
    fout.writelines("6\n")
    quit()

fout.writelines("7\n")

