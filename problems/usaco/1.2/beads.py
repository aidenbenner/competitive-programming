"""
ID: aiden.b1
LANG: PYTHON3
TASK: beads
"""
fin = open ('beads.in', 'r')
fout = open ('beads.out', 'w')

fin.readline()
beads = fin.readline()[0:-1]

i = 0
last = 'a'
max_run = 0
while i < len(beads):
    curr_run = 0
    k = 0
    color = beads[i]
    while k < len(beads):
        ind = (i + k) % len(beads)
        if color == 'w' or beads[ind] == color or beads[ind] == 'w':
            if beads[ind] != 'w':
                color = beads[ind]
            curr_run += 1
            k += 1
        else:
            break

    k = 0
    color = beads[i - 1]
    while k < len(beads):
        ind = (i - k - 1) % len(beads)
        if color == 'w' or beads[ind] == color or beads[ind] == 'w':
            if beads[ind] != 'w':
                color = beads[ind]
            curr_run += 1
            k += 1
        else:
            break

    if curr_run > max_run:
        max_run = curr_run
    i += 1

fout.write(str(min(max_run, len(beads))) + "\n")
