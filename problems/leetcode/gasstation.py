class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """

        diff = [gas[i] - cost[i] for i in range(len(gas))]

        sum = 0
        for x in diff:
            sum += x
        if sum < 0:
            return -1

        curr = 0
        start = 0
        i = 0
        for x in diff:
            curr += x
            if curr < 0:
                curr = 0
                start = i + 1
            i += 1
        return start


s = Solution()
s.canCompleteCircuit([1,2,3,4,5],[3,4,5,1,2])





