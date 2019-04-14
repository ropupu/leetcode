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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
        answer.push_back(root->val);
        if (root->left) {
            std::vector<int> left = preorderTraversal(root->left);
            answer.insert(answer.end(), left.begin(), left.end());
        }
        if (root->right) {
            std::vector<int> right = preorderTraversal(root->right);
            answer.insert(answer.end(), right.begin(), right.end());
        }
        return answer;
    }
};
