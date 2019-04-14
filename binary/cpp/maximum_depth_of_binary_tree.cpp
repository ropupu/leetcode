/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) {
        return 0;
    }

    if (!root.left && !root.right) {
        return 1;
    }
    
    let leftDepth = 0;
    let rightDepth = 0;
    if (root.left) {
        leftDepth = maxDepth(root.left);
    }
    
    if (root.right) {
        rightDepth = maxDepth(root.right);
    }
    
    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
};
