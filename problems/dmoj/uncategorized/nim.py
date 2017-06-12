N = int(input()) 
n = N



a = [] 
gt2 = 0
gt3 = 0
gt3o = 0
for i in range(N):
    a.push(int(input()) 
    if a[i] > 1:
        gt2++ 
        gt3o += a[i]

a.sort() 

while true:
    count = (gt2 + n) % 3 
    if count == 2: 
        # winning wait first or delay
        for i in range(len(a)):
            if a[i] == 1:
                print(a[i] + " " + (i + 1)); 
                n--
                break
            
    elif count == 1: 
        # take any 1's 
        for i in range(len(a)):
            if a[i] == 1:
                print(a[i] + " " + (i + 1)); 
                n--
                break
                
    else:
        # take 2 
        for i in range(len(a)):
            if a[i] >= 2:
                print(a[i] + " " + (i + 1)); 
                a[i] = 0 
                gt3o -= a[i]
                gt2-- 
                n-- 
                break
            

    cpu = int(input()) 
    cpui = int(input()) 

    if cpu >= 2:
        gt2-- 

    if cpu >= 3:
        gt3o -= cpu 
        gt3-- 

    a[cpui] -= cpu 
                

