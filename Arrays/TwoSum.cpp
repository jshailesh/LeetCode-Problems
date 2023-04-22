// LC 1: Two Sum
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

#include <vector>
#include <unordered_map>

std::vector<int> two_sum(const std::vector<int>& nums, int target) {
    std::vector<int> result;
    std::unordered_map<int, int> index_map;

    for (auto i = 0; i < nums.size(); ++i) {
        if (auto summand = target - nums[i]; index_map.find(summand) != index_map.end()) {
            return {i, index_map[summand]};
        }

        index_map.emplace(nums[i], i);
    }
    
    // Dummy return - we will never get here
    return {};
}