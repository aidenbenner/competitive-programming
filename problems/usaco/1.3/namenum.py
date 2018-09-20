"""
ID: aiden.b1
LANG: PYTHON3
TASK: namenum
"""
fin = open ('namenum.in', 'r')
fout = open ('namenum.out', 'w')

dictionary = open('dict.txt', 'r')
words = dictionary.readlines()


dct = set()
for w in words:
    dct.add(w.strip())


num = fin.readline().strip()


mp = {
    2 : ['A', 'B', 'C'],
    3 : ['D', 'E', 'F'],
    4 : ['G', 'H', 'I'],
    5 : ['J', 'K', 'L'],
    6 : ['M', 'N', 'O'],
    7 : ['P', 'R', 'S'],
    8 : ['T', 'U', 'V'],
    9 : ['W', 'X', 'Y'],
}


strs = [""]
ind = 0

print(num)
for n in num:
    print(mp)
    next_strs = []
    for s in strs:
        if int(n) not in mp:
            continue
        for c in mp[int(n)]:
            next_strs.append(s + c)
    strs =  next_strs

strs.sort()
printed = set()

for s in strs:
    print(s)
    if s in dct and not s in printed:
        printed.add(s)
        fout.write(s + '\n')
if len(printed) == 0:
    fout.write("NONE\n")
