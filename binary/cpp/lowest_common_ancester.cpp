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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        std::vector<TreeNode*> ppath;
        std::vector<TreeNode*> qpath;
        this->searchNode(root, p, &ppath);
        this->searchNode(root, q, &qpath);
        int psize = ppath.size();
        int qsize = qpath.size();
        int minSize;
        int maxSize;
        std::vector<TreeNode*>* targetPath;
        std::vector<TreeNode*>* comparePath;
        if (psize >= qsize) {
            minSize = qsize;
            maxSize = psize;
            targetPath = &ppath;
            comparePath = &qpath;
        } else {
            minSize = psize;
            maxSize = qsize;
            targetPath = &qpath;
            comparePath = &ppath;
        }

        for (int i = 0; i < maxSize; i++) {
            if (i < minSize && ((*targetPath)[maxSize - 1 - i])->val == ((*comparePath)[minSize - 1 - i])->val) {
                continue;
            }
            return ((*targetPath)[maxSize - 1 - i + 1]);
        }
        return root;
    }
    bool searchNode(TreeNode* root, TreeNode* target, std::vector<TreeNode*>* path) {
        if (root->val == target->val) {
            (*path).push_back(root);
            return true;
        }
        if (root->left) {
            if (this->searchNode(root->left, target, path)) {
                (*path).push_back(root);
                return true;
            }
        }
        if (root->right) {
            if (this->searchNode(root->right, target, path)) {
                (*path).push_back(root);
                return true;
            }
        }
        return false;
    }
};
