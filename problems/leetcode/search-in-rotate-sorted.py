class Solution:
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0: return -1;
        if len(nums) == 1: return 0 if nums[0] == target else -1;
        bot = 0
        top = len(nums) - 1

        while (bot < top):
            mid = (bot + top) // 2

            if nums[bot] < nums[top]:
                offset = bot
                break
            if top - bot <= 1:
                offset = top
                break
            if nums[mid] < nums[top]:
                # divide in bottom half
                top = mid
            else:
                bot = mid

        bot = 0
        top = len(nums) - 1
        n = len(nums)

        def f(x):
            return nums[(x + offset) % n]

        mid = 0
        while (bot < top):
            mid = (bot + top) // 2

            if f(mid) == target:
                return (mid + offset) % n

            if target < f(mid):
                # divide in bottom half
                top = mid - 1
            else:
                bot = mid + 1
        if f(bot) == target:
            return (bot + offset) % n
        if f(top) == target:
            return (top + offset) % n

        return -1
