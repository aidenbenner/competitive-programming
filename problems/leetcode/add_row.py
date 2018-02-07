class Solution:
    def addOneRow(self, root, v, d):
        return self.f(root,v,d, True)


    def f(self,root,v,d,left):
        """
        :type root: TreeNode
        :type v: int
        :type d: int
        :rtype: TreeNode
        """
        if root is None:
            return TreeNode(v) if d == 1 else None

        if d == 1:
            out = TreeNode(v)
            if left is True:
                out.left = root
            else:
                out.right = root
            return out
        else:
            root.left = self.f(root.left, v, d - 1, True)
            root.right = self.f(root.right, v, d - 1, False)
            return root

