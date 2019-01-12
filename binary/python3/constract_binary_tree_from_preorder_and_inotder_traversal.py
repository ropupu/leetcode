# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0 or len(preorder) == 0:
            return None
        
        root = preorder[0]
        preorder.pop(0)
        
        treeNode = TreeNode(root)
        
        if len(inorder) == 1:
            return treeNode
        
        rootIndex = inorder.index(root)
            
        if rootIndex > 0:
            treeNode.left = self.buildTree(preorder, inorder[:rootIndex])
            
        if rootIndex < len(inorder):
            treeNode.right = self.buildTree(preorder, inorder[rootIndex+1:])
        
        return treeNode

