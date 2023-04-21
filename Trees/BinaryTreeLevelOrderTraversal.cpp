#include <iostream>
#include <vector>
#include <queue>

#include "Node.hpp"

class Solution {
public:
    std::vector<std::vector<int>> level_order_traversal(const TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        std::queue<const TreeNode*> nodes_seen;
        nodes_seen.emplace(root);

        std::vector<std::vector<int>> result;
        while (!nodes_seen.empty()) {
            auto num_nodes = nodes_seen.size();
            std::vector<int> vals(num_nodes);
            for (auto i = 0; i < num_nodes; ++i) {
                auto node = nodes_seen.front();
                vals[i] = node->val;
                nodes_seen.pop();

                if (node->left) {
                    nodes_seen.emplace(node->left);
                }

                if (node->right) {
                    nodes_seen.emplace(node->right);
                }
            }
            result.emplace_back(vals);
        }

        return result;
    } 

};