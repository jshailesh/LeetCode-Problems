// LC 1448
// Given a binary tree root, a node X in the tree is named good if in the path from root to X 
// there are no nodes with a value greater than X.
// Return the number of good nodes in the binary tree.

class Solution {
public:
    int goodNodes(const TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        dfs(root, root->val);
        return _count;
    }

private:
    int _count = 0;
    void dfs(const TreeNode* node, int max_so_far) {
        if (node->val >= max_so_far) {
            max_so_far = node->val;
            ++_count;
        }

        if (node->left) {
            dfs(node->left, max_so_far);
        }

        if (node->right) {
            dfs(node->right, max_so_far);
        }
    }
};