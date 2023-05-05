// LC 230
// Kth Smallest Element in a BST

#include "Node.hpp"

class Solution {
public:
    int kthSamllest(const TreeNode* root, int k) {
        dfs(root, k);
        return kth;
    }

private:
    int kth;
    int count = 0;
    void dfs(const TreeNode* node, int k) {
        if (node->left) {
            dfs(node->left, k);
        }

        ++count;
        if (k == count) {
            kth = node->val;
            return;
        }

        if (node->right) {
            dfs(node->right, k);
        }
    }

};