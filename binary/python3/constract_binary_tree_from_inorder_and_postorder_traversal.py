# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0 or len(postorder) == 0:
            return None
        
        root = postorder[-1]
        postorder.pop(-1)
        
        treeNode = TreeNode(root)
        
        if len(inorder) == 1:
            return treeNode
        
        rootIndex = inorder.index(root)
            
        if rootIndex < len(inorder):
            treeNode.right = self.buildTree(inorder[rootIndex+1:], postorder)
            
        if rootIndex > 0:
            treeNode.left = self.buildTree(inorder[:rootIndex], postorder)
        
        return treeNode

