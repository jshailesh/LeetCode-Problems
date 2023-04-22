// LC 238
// Given an integer array nums, return an array answer such that answer[i] is equal to the product 
// of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

#include <vector>

// T(n) = O(n) and S(n) = O(n)
std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    auto nelems = nums.size();
    std::vector<int> left(nelens), right(nelems);
    left[0] = 1;
    for (auto i = 1; i < nelems; ++i) {
        left[i] = left[i - 1] * nums[i - 1];
    }
    
    right[nelems - 1] = 1;
    for (int i = nelems - 2; i >= 0; --i) {
        right[i] = right[i + 1] * nums[i + 1];
    }

    std::vector<int> result(nelems);
    for (auto i = 0; i < nelems; ++i) {
        result[i] = left[i] * right[i];
    }

    return result;
}

std::vector<int> productOfArrayExceptSelfEfficient(const std::vector<int>& nums) {
    auto nelems = nums.size();
    vector<int> result(nelems, 1);
    auto left{1};
    auto right{1};

    for (auto i = 0; i < nelems; ++i) {
        result[i] *= left;
        left *= nums[i];
        result[nelems - 1 - i] *= right;
        right *= nums[nelems - 1 - i];
    }

    return result;
}