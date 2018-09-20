"""
ID: aiden.b1
LANG: PYTHON3
TASK: milk2
"""
fin = open ('milk2.in', 'r')
fout = open ('milk2.out', 'w')

N = int(fin.readline())

arr = []
for x in range(1000000):
    arr.append(0)

top_range = 0
bot_range = 100000000000000
for x in range(N):
    s = fin.readline().split()
    a = int(s[0])
    b = int(s[1])
    top_range = max(top_range, b)
    bot_range = min(bot_range, a)

    arr[a] += 1
    arr[b] -= 1

curr_count = 0
milked = 0
maxml = 0
i = 0
for x in arr:
    i += 1
    curr_count += x
    # print(str(i) + " " + str(curr_count) + " " + str(milked))
    if curr_count > 0:
        milked += 1
    else:
        milked = 0
    maxml = max(maxml, milked)

curr_count = 0
milked = 0
nmaxml = 0
i = 0
for x in arr:
    if i < bot_range:
        i += 1
        continue
    if i >= top_range:
        break
    curr_count += x
    if curr_count == 0:
        milked += 1
    else:
        milked = 0
    nmaxml = max(nmaxml, milked)
    i += 1

fout.write(str(maxml) + " " + str(nmaxml) + "\n")
