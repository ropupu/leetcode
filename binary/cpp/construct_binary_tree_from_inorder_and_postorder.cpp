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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        return handle(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* handle(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
        int rootVal = postorder[postorderEnd];
        int rootPosition = std::distance(inorder.begin(), (std::find(inorder.begin(), inorder.end(), rootVal)));
        TreeNode *tree;
        tree = new TreeNode(rootVal);
        int rightLength = inorderEnd - rootPosition;
        int leftLength = rootPosition - inorderStart;
        if (rootPosition < inorderEnd) {
            tree->right = handle(inorder, postorder, rootPosition + 1, inorderEnd, postorderEnd - 1 - rightLength, postorderEnd - 1);
        }
        if (rootPosition > inorderStart) {
            int leftLength = rootPosition - inorderStart;
            tree->left = handle(inorder, postorder, inorderStart, rootPosition - 1,  postorderEnd - rightLength - 1 - leftLength,postorderEnd - rightLength - 1);
        }
        return tree;
    }
};

