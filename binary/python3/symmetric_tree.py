# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
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
            if node is None:
                level.append(None)
            else:
                level.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
                
            traversedSize += 1
            
            if len(level) == levelSize:
                traversalResult.append(level)
                level = []
                levelSize = len(queue) - traversedSize
                
        for levelNodes in traversalResult:
            size = len(levelNodes)
            if size == 1:
                continue
                
            halfSize = int(size/2)
            for i in range(halfSize):
                if levelNodes[i] != levelNodes[size-i-1]:
                    return False

        return True

def stringToTreeNode(input):
    input = input.strip()
    input = input[1:-1]
    if not input:
        return None

    inputValues = [s.strip() for s in input.split(',')]
    root = TreeNode(int(inputValues[0]))
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(inputValues):
        node = nodeQueue[front]
        front = front + 1

        item = inputValues[index]
        index = index + 1
        if item != "null":
            leftNumber = int(item)
            node.left = TreeNode(leftNumber)
            nodeQueue.append(node.left)

        if index >= len(inputValues):
            break

        item = inputValues[index]
        index = index + 1
        if item != "null":
            rightNumber = int(item)
            node.right = TreeNode(rightNumber)
            nodeQueue.append(node.right)
    return root

def main():
    import sys
    import io
    def readlines():
        for line in io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8'):
            yield line.strip('\n')

    lines = readlines()
    while True:
        try:
            line = next(lines)
            root = stringToTreeNode(line);
            
            ret = Solution().isSymmetric(root)

            out = (ret);
            print(out)
        except StopIteration:
            break

if __name__ == '__main__':
    main()

