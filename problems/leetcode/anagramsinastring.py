from collections import defaultdict

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if len(p) > len(s):
            return []
        l = defaultdict(int)
        for j in range(len(p)):
            l[p[j]] += 1

        out = []
        k = defaultdict(int)
        for x in range(len(s)):
            k[s[x]] += 1
            if x - len(p) >= 0:
                k[s[x - len(p)]] -= 1
            add = True
            for key in l:
                if k[key] != l[key]:
                   add = False
            if add:
                if x - len(p) + 1 >= 0:
                    out.append(x - len(p) + 1)
        return out

l = defaultdict(int)
j = defaultdict(int)
j[5] += 1;
l[5] += 1;
print(l == j)

print(range(1))

s = Solution()
print(s.findAnagrams("cbaebabacd", "abc"))





