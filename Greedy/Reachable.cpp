// LC 55
// You are given an integer array nums. You are initially positioned at the array's first index, 
// and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

#include <vector>
#include <algorithm>

class Solution_Greedy {
public:
    bool canJump(std::vector<int>& nums) {
        size_t nelems = nums.size();
        int reachable = 0;

        for (auto i = 0; i < nelems; ++i) {
            if (i > reachable) {
                return false;
            }

            reachable = std::max(reachable, i + nums[i]);
        }

        return true;
    }

};

class Solution_DynamicProgramming {
public:
    bool canJump(std::vector<int>& nums) {
        auto nelems = nums.size();
        std::vector<int> table(nelems, false);

        // Base Case
        table[0] = true;

        for (auto i = 1; i < nelems; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (table[j] && i - j <= nums[j]) {
                    table[i] = true;
                    break;
                }
            }
        }

        return table.back();
    }

};