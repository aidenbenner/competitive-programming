s = input().split(" ")
x = s[1]

if x == "":
    print("")

if s[0] == "D":
    i = 0
    out = ""
    while i < len(x):
        j = 0
        while j < int(x[i + 1]):
            out += x[i]
            j += 1
        i += 2
else:
    i = 1
    out = ""
    curr_run = 1
    while i < len(x):
        if x[i] == x[i-1]:
            curr_run += 1
        else:
            out += x[i-1]
            out += str(curr_run)
            curr_run = 1
        i += 1
    out += x[i-1]
    out += str(curr_run)
    curr_run = 0
    
print(out)

        







