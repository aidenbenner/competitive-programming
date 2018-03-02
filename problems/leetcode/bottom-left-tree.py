# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def f(self, root):
        if root is None: return [-10,0]
        if (root.left is None) and (root.right is None):
            return [0, root.val]

        l = self.f(root.left)
        r = self.f(root.right)
        l[0] += 1
        r[0] += 1

        if r[0] > l[0]:
            return r
        else:
            return l


    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.f(root)[1]

