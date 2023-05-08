// LC 152
// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

#include <vector>

class Solution {
public:
    int maxProduct(const std::vector<int>& nums) {
        auto nelems = nums.size();

        // Create tables to store maximum and minimum products upto index i for each 
        // i from 0 to nelems - 1
        std::vector<int> TMax(nelems);
        std::vector<int> TMin(nelems);

        // Trivially
        TMax[0] = nums[0];
        TMin[0] = nums[0];
        int maximum_product = nums[0];

        // Now, populate the values for each index
        for (auto idx = 1; idx < nelems; ++idx) {
            TMax[idx] = std::max(nums[idx], nums[idx] * (nums[idx] >= 0 ? TMax[idx - 1] : TMin[idx - 1]));
            TMin[idx] = std::min(nums[idx], nums[idx] * (nums[idx] >= 0 ? TMin[idx - 1] : TMax[idx - 1]));
            maximum_product = std::max(maximum_product, TMax[idx]);
        }

        return maximum_product;
    }
};