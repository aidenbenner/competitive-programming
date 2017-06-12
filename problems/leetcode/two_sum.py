class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        lookup = {} 
        i = 0; 
        for v in nums:
            if v in lookup:
                return [lookup[v],  i] 
            lookup.update({target - v: i}) 
            i += 1

