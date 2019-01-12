# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        
        if root.left is not None and root.right is not None:
            root.left.next = root.right
        
        if root.next is not None and root.right is not None:
            root.right.next = root.next.left
        
        if root.left is not None:
            self.connect(root.left)
            
        if root.right is not None:
            self.connect(root.right)

