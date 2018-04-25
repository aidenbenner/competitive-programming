class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        out = ""
        for x in range(numRows):
            j = 0
            while j < len(s)
                a = x + 2 * (numRows -  x % numRows)
                b += x + numRows * 2 - 1

                if a != b:
                    out += s[a]
                    out += s[b]
                else:
                    out += s[a]

                j += 2 * numRows

        return out

