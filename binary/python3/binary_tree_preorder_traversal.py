# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        preorder = []
        
        if root is None:
            return preorder
        
        preorder.append(root.val)
        
        if root.left is not None:
            preorder += self.preorderTraversal(root.left)
        if root.right is not None:
            preorder += self.preorderTraversal(root.right)
        
        return preorder

