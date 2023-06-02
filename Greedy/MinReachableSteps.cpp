// LC 55
// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at nums[i], you can jump to any nums[i + j] where:
// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. 
// The test cases are generated such that you can reach nums[n - 1].

#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int start = 0;
        int end = 0;
        int nsteps = 0;
        int max_end = 0;
        int nelems = nums.size();

        while (end < nelems - 1) {
            for (int i = start; i <= end; ++i) {
                ++nsteps;
                max_end = std::max(max_end, i + nums[i]);

                if (max_end >= nelems - 1) {
                    return nsteps;
                }
            }

            start = end + 1;
            end = max_end;
        }

        return nsteps;
    }
};