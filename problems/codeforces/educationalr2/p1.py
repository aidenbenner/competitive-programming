

s = str(input())
s = s.replace(";", ",")

words = s.split(",")

out = []
b = []
for w in words:
    if '.' in w:
        b.append(w)
        continue
    try:
        x = int(w)
        if len(w) > 1:
            if w[0] == '0':
                b.append(w)
                continue
        out.append(w)
    except Exception as e:
        b.append(w)
if len(out) == 0:
    print("-")
else:
    print("\"" + ",".join(out) + "\"")
if len(b) == 0:
    print("-")
else:
    print("\"" + ",".join(b) + "\"")

