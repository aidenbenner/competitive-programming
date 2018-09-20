"""
ID: aiden.b1
LANG: PYTHON3
TASK: gift1
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

NP = int(fin.readline())

names = []
mp = {}
for x in range(NP):
    names.append(fin.readline())
    mp[names[-1]] = 0

for x in range(NP):
    a = fin.readline()
    line = fin.readline().split()
    val = int(line[0])
    split = int(line[1])

    mp[a] -= val
    if split == 0:
        mp[a] += val
        continue

    mp[a] += val % split
    val_per = val // split
    for y in range(split):
        mp[fin.readline()] += val_per

for x in names:
    fout.write (x[0:-1] + " " + str(mp[x]) + '\n')

fout.close()

