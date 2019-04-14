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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right) {
            return sum == root->val;
        }
        int restVal = sum - root->val;
        bool leftAnswer, rightAnswer;
        leftAnswer = rightAnswer = false;
        if (root->left) {
            leftAnswer = hasPathSum(root->left, restVal);
        }
        if (root->right) {
            rightAnswer = hasPathSum(root->right, restVal);
        }
        return (leftAnswer || rightAnswer);
    }
};