class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        i = 0
        for x in nums:
            mp = set()

            k = 0
            for y in nums:
                if k != i:
                    mp.add(nums[y])
                    
                k++

            i++



        


        
