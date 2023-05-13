// LC 105
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
// binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

#include <algorithm>
#include <vector>
#include <unordered_map>
#include "Node.hpp"

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int idx = 0;
        std::for_each(inorder.begin(), inorder.end(), [this, &idx] (auto nodeval) {
            root_index_map.emplace(nodeval, idx);
        });

        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
            inorder, 0, inorder.size() - 1);
    }

private:
    std::unordered_map<int, int> root_index_map;
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, int pstart, int pend,
        const std::vector<int>& inorder, int istart, int iend) {
        // Base Case 1:
        if (istart > iend) {
            return nullptr;
        }

        // Base Case 2:
        if (istart == iend) {
            return new TreeNode(inorder[istart]);
        }

        // Get the root value for the current subtree
        int root_val = preorder[pstart];
        TreeNode* subtree_root = new TreeNode(root_val);

        // Get the root index in the inorder traversal
        int root_idx = root_index_map[root_val];
        int left_subtree_size = root_idx - istart;

        // Attach the left subtree
        subtree_root->left = buildTreeHelper(preorder, pstart + 1, pstart + left_subtree_size, 
            inorder, istart, root_idx - 1);

        // Attach the right subtree
        subtree_root->right = buildTreeHelper(preorder, pstart + left_subtree_size + 1, pend, 
            inorder, root_idx + 1, iend);

        return subtree_root;
    }
}