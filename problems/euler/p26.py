from decimal import *

for i in range(1, 1001):
    res = Decimal(1) / Decimal(i)
    print(i, res)
