s = input()

i = 0

mp = [0 for x in range(26)]

out = ""
while i < len(s):
    mp[ord(s[i]) - ord('a')] += 1
    i += 1

front = 0
end = len(mp) - 1

while front < len(mp) and mp[front] % 2 != 1:
    front += 1
while end > 0 and mp[end] % 2 != 1:
    end -= 1
while front < end:
    mp[end] -= 1
    mp[front] += 1
    front += 1
    end -= 1
    while front < len(mp) and mp[front] % 2 != 1:
        front += 1
    while end > 0 and mp[end] % 2 != 1:
        end -= 1

out = ""
for i in range(len(mp)):
    for k in range(mp[i] // 2):
        out += chr(i + ord('a'))

rev = out[::-1]
if front < len(mp) and mp[front] % 2 == 1:
    out += chr(front + ord('a'))

print(out + rev)
