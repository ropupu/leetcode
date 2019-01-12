# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root, depth=1):
        """
        :type root: TreeNode
        :type depth: int
        :rtype: int
        """
        if root is None:
            return 0
        
        answer = depth
        
        if root.left is not None:
            answer = max(answer, self.maxDepth(root.left, depth+1))
        
        if root.right is not None:
            answer = max(answer, self.maxDepth(root.right, depth+1))
        
        return answer

