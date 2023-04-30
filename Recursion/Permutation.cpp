// LC 46
// Given an array nums of distinct integers, return all the possible permutations. 
// You can return the answer in any order.

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        dfs(nums, 0);
        return _result;
    }
    
private:
    std::vector<int> _slate;
    std::vector<std::vector<int>> _result;
    void dfs(std::vector<int>& nums, int cidx) {
        if (nums.size() == cidx) {
            _result.emplace_back(_slate);
            return;
        }

        // Recursive Case:
        for (auto i = cidx; i < nums.size(); ++i) {
            std::swap(nums[i], nums[cidx]);
            _slate.emplace_back(nums[cidx]);
            dfs(nums, cidx + 1);
            _slate.pop_back();
            std::swap(nums[i], nums[cidx]);
        }
    }
};