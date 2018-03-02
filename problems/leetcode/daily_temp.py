import bisect
class Solution:
    def dailyTemperatures(self, t):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """

        mp = []
        for i in range(0,120):
            mp.append(0)

        out = [0] * len(t)
        for z in range(len(t)):
            i = len(t) - 1 - z
            curr = t[i]

            mp[t[i]] = 1
            for k in range(30,120):
                if not mp[k] == 0:
                    mp[k] += 1

            occur = False
            for k in range(curr + 1,120):
                if not mp[k] == 0:
                    if not occur:
                        occur = True
                        out[i] = mp[k]
                    else:
                        out[i] = min(mp[k], out[i])

        for k in range(len(t)):
            if not out[k] == 0:
                out[k] -= 2

        return out
