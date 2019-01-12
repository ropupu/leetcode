class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        inorder = []
        
        if root is None:
            return inorder
        
        if root.left is not None:
            inorder += self.inorderTraversal(root.left)
            
        inorder.append(root.val)
        
        if root.right is not None:
            inorder += self.inorderTraversal(root.right)
        
        return inorder

