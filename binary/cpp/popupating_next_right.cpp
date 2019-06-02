/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        
        std::queue<Node*> que;
        std::queue<int> layerQueue;
        
        que.push(root);
        layerQueue.push(0);
        
        int layer;
        while (que.size() > 0) {
            Node* target = que.front();
            layer = layerQueue.front();
            que.pop();
            layerQueue.pop();
            target->next = NULL;
            if (que.size() > 0 && layerQueue.front() == layer) {
                target->next = que.front();
            }
            
            if (target->left) {
                que.push(target->left);
                layerQueue.push(layer + 1);
            }
            if (target->right) {
                que.push(target->right);
                layerQueue.push(layer + 1);
            }
        }
        return root;
    }
};

