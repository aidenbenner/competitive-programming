import math
class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """

        if k == 2:
            out = [1,3,2]
            out.extend([x for x in range(4,n+1)])
            return out

        # k == 2

        start = k + 1
        out = []

        order = True
        for x in range(start//2):
            if order:
                out.append(start - x)
                out.append(1 + x)
                order = False
            else:
                out.append(start - x)
                out.append(1 + x)
                order = True
        if k % 2 == 0:
            out.append(start//2 + 1)

        out = out[::-1]

        for x in range(start + 1, n + 1):
            out.append(x)

        return out 
