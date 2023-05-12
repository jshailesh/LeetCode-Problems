// LC 15
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        // Since the proposed algorithm is going to be O(n^2), we can sort the input without
        // adding to the cost
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> triplets;

        int i = 0;
        int last = nums.size() - 1;
        while (i < last) {
            auto first = nums[i];

            // Making the first a pivot, find the two numbers that when added to first sum to zero
            int j = i + 1;
            int k = last;
            while (j < k) {
                int second = nums[j];
                int third = nums[k];

                int sum = first + second + third;

                if (sum == 0) {
                    triplets.push_back({first, second, third});
                }

                // Sum is smaller, move the left pointer forward until a number that is
                // different from the previous one is found
                if (sum <= 0) {
                    while (j < k && nums[j] == second) {
                        ++j;
                    }
                }

                // Sum is larger, move the right pointer backward until a number that is
                // different from the previous is found
                if (sum >= 0) {
                    while (j < k && nums[k] == third) {
                        --k;
                    }
                }
            }

            // Move onto the next pivot; make sure that it is a different number
            while (i < last && nums[i] == first) {
                ++i;
            }
        }

        return triplets;
    }

};