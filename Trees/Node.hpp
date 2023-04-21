#pragma once

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(int aVal) : val{aVal} {}
    TreeNode(int aVal, TreeNode* aLeft, TreeNode* aRight) :
    val{aVal}, left{aLeft}, right{aRight} {}
};