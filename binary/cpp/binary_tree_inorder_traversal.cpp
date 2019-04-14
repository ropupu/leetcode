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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
        if (root->left) {
            std::vector<int> left = inorderTraversal(root->left);
            answer.insert(answer.end(), left.begin(), left.end());
        }
        answer.push_back(root->val);
        if (root->right) {
            std::vector<int> right = inorderTraversal(root->right);
            answer.insert(answer.end(), right.begin(), right.end());
        }
        return answer;
    }
};
