// LC 98
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include "Node.hpp"
#include <tuple>

class Solution {
public:
    bool isValidBST(const TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        (void) dfs(root);
        return _isBST;
    }

private:
    bool _isBST = true;
    std::tuple<bool, int, int> dfs(const TreeNode* node) {
        bool isNodeBST = true;
        int maxVal = node->val;
        int minVal = node->val;

        // Base Case: Leaf Node
        // Nothing special needs to be done

        // Recursive Case: Interior Node
        if (node->left) {
            auto [isBST, myMin, myMax] = dfs(node->left);
            minVal = std::min(minVal, myMin);
            maxVal = std::max(maxVal, myMax);
            if (!isBST || node->val <= myMax) {
                isNodeBST = false;
            }
        }

        if (node->right) {
            auto [isBST, myMin, myMax] = dfs(node->right);
            minVal = std::min(minVal, myMin);
            maxVal = std::max(maxVal, myMax);
            if (!isBST || node->val >= myMin) {
                isNodeBST = false;
            }
        }

        if (!isNodeBST) {
            _isBST = false;
        }

        return {isNodeBST, minVal, maxVal};
    }
}