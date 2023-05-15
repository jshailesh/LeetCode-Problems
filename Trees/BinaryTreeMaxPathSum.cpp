// LC 124
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has 
// an edge connecting them. A node can only appear in the sequence at most once. 
// Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include "Node.hpp"
#include <cstdlib>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        (void) dfs_helper(root);
        return max_sum;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
private:
    int max_sum = INT_MIN;
    int dfs_helper(const TreeNode* node) {
        int max_sum_thru_node = node->val;
        int max_vsum_thru_node = node->val;

        if (node->left) {
            auto lsum = dfs_helper(node->left);
            max_sum_thru_node = std::max(max_sum_thru_node, max_sum_thru_node + lsum);
            max_vsum_thru_node = max_sum_thru_node;
        }

        if (node->right) {
            auto rsum = dfs_helper(node->right);
            max_sum_thru_node = std::max(max_sum_thru_node, max_sum_thru_node + rsum);
            max_vsum_thru_node = std::max(max_vsum_thru_node, 
                std::max(node->val + rsum, max_vsum_thru_node + rsum));
        }

        if (max_vsum_thru_node > max_sum) {
            max_sum = max_vsum_thru_node;
        }
        
        return max_sum_thru_node;
    }
};