"""
ID: aiden.b1
LANG: PYTHON3
TASK: milk2
"""
fin = open ('milk2.in', 'r')
fout = open ('milk2.out', 'w')

N = int(fin.readline())

arr = []
for x in range(100000):
    arr.append(0)

top_range = 0
for x in range(N):
    s = fin.readline().split()
    a = int(s[0])
    b = int(s[1])
    top_range = max(top_range, b)

    arr[a] += 1
    arr[b - 1] -= 1

curr_count = 0
milked = 0
maxml = 0
for x in arr:
    curr_count += arr[x]
    if curr_count > 0:
        milked += 1
    maxml = max(maxml, milked)

curr_count = 0
milked = 0
nmaxml = 0
for x in arr:
    curr_count += arr[x]
    if curr_count == 0:
        nmilked += 1
    nmaxml = max(nmaxml, milked)

fout.write(maxml + " " + nmaxml + "\n")
