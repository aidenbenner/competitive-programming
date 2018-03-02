class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """

        d = {}
        for x in s:
            if x in d:
                d[x] += 1
            else:
                d[x] = 1

        out = ""
        for key, val in sorted(d, key=d.get, reversed=true ):
            for x in range(val):
                out += key
        return out







