// LC 110
// Given a binary tree, determine if it is height-balanced
#include "Node.hpp"

class Solution {
public:
    bool isBalanced(const TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        (void) dfs(root);
        return _balanced;
    }

private:
    bool _balanced = true;
    int dfs(const TreeNode* node) {
        int left_ht = 0;
        int right_ht = 0;

        // Base Case: Leaf Node
        // Nothing needs to be done

        // Recursive Case: Interior Node
        if (node->left) {
            left_ht = 1 + dfs(node->left);
        }

        if (node->right) {
            right_ht = 1 + dfs(node->right);
        }

        if (std::abs(left_ht - right_ht) > 1) {
            _balanced = false;
        }

        return std::max(left_ht, right_ht);
    }
};
