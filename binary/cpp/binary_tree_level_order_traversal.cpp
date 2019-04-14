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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        vector<int> levelAnswer;
        TreeNode* target;
        std::queue<TreeNode*> que;
        int levelSize;

        if (!root) {
            return answer;
        }
        que.push(root);
        while (!que.empty()) {
            levelSize = que.size();
            levelAnswer.clear();
            for (int i = 0; i < levelSize; i++) {
                target = que.front();
                levelAnswer.push_back(target->val);
                if (target->left) {
                    que.push(target->left);
                }
                if (target->right) {
                    que.push(target->right);
                }
                que.pop();
            }
            answer.push_back(levelAnswer);
        }
        return answer;
    }
};
