// LC 572
// Given the roots of two binary trees root and subRoot, return true if there is a subtree of 
// root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this 
// node's descendants. The tree tree could also be considered as a subtree of itself.

#include "Node.hpp"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (nullptr == root) {
            return false;
        }

        // Check if the currrent node of the first tree has the same subtree as the
        // second tree
        if (areSame(root, subRoot)) {
            return true;
        }

        // Check if either left or right have the same tree as the other tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool areSame(const TreeNode* first, const TreeNode* second) const {
        if (nullptr == first || nullptr == second) {
            return first == second;
        }

        // The two nodes must be the same
        if (first->val != second->val) {
            return false;
        }

        // Both subtrees of the two trees must also be the same
        return areSame(first->left, second->left) && 
            areSame(first->right, second->right);
    }

};