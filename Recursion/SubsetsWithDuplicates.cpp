// LC 90
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
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
        // Get the number of repeats of the current item
        int ndups = 0;
        for (auto i = cidx; i < nums.size(); ++i) {
            if (nums[i] != nums[cidx]) {
                break;
            }
            ++ndups;
        }

        // Exclusion Case:
        dfs(nums, cidx + ndups);

        // Inclusion Case:
        // Multiway inclusion:
        // Essentially in every iteration, we push i + 1 numbers of nums[cidx]
        // and call the dfs and then pop those. But to avoid push and pop the 
        // same item, we can do the pops at the end
        for (auto i = 0; i < ndups; ++i) {
            _slate.emplace_back(nums[cidx]);
            dfs(nums, cidx + ndups);
        }

        // Restore the slate
        for (auto i = 0; i < ndups; ++i) {
            _slate.pop_back();
        }
    }
    
};