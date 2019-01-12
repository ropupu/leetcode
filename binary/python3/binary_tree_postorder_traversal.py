# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        postorder = []
        
        if root is None:
            return postorder
        
        if root.left is not None:
            postorder += self.postorderTraversal(root.left)
            
        if root.right is not None:
            postorder += self.postorderTraversal(root.right)
            
        postorder.append(root.val)
        
        return postorder

