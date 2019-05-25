/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        return handle(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
    TreeNode* handle(vector<int>& inorder, vector<int>& preorder, int inorderStart, int inorderEnd, int preorderStart, int preorderEnd) {
        int rootVal = preorder[preorderStart];
        int rootPosition = std::distance(inorder.begin(), (std::find(inorder.begin(), inorder.end(), rootVal)));
        TreeNode *tree;
        tree = new TreeNode(rootVal);
        int rightLength = inorderEnd - rootPosition;
        int leftLength = rootPosition - inorderStart;
        if (rootPosition > inorderStart) {
            tree->left = handle(inorder, preorder, inorderStart, rootPosition - 1,  preorderStart + 1, preorderEnd - rightLength);
        }
        if (rootPosition < inorderEnd) {
            tree->right = handle(inorder, preorder, rootPosition + 1, inorderEnd, preorderStart + leftLength + 1, preorderEnd);
        }
        return tree;
    }
};
