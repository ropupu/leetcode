# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:        
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        queue = []
        traversalResult = []
        
        if root is None:
            return traversalResult
        
        queue.append(root)
        
        level = []
        levelSize = len(queue)
        traversedSize = 0
        
        for node in queue:
            level.append(node.val)
            if node.left is not None:
                queue.append(node.left)
                
            if node.right is not None:
                queue.append(node.right)
                
            traversedSize += 1
            
            if len(level) == levelSize:
                traversalResult.append(level)
                level = []
                levelSize = len(queue) - traversedSize

        return traversalResult

