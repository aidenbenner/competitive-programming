class Solution:
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """

        allowed = [[] for x in range(N)]
        for i in range(1, N + 1):
            for k in range(1, N + 1):
                if i % k == 0 or k % i == 0:
                    if not k in allowed[i - 1]:
                        allowed[i - 1].append(k)
                    if not i in allowed[i - 1]:
                        allowed[i - 1].append(i)

        print(allowed)

        def solve(curr, remaining):
            if len(remaining) == 0:
                return 1
            total = 0
            for x in allowed[curr]:
                if x in remaining:
                    remaining.remove(x)
                    total += solve(curr + 1, remaining)
                    remaining.append(x)
            return total

        return solve(0, [x for x in range(1,N + 1)])


