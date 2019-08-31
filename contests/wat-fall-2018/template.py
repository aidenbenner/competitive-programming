import math

N = int(input())

mp = []
for i in range(N):
    mp.append(False)

nums = input().split(" ")
for x in nums:
    x = int(x)
    x -= 1
    mp[x] = True

for i in range(N):
    if not mp[i]:
        print(i + 1)
    


