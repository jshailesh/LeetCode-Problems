// LC 300
// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence

#include <algorithm>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> subseq;
        subseq.push_back(nums.front());

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > subseq.back()) {
                subseq.push_back(nums[i]);
            } else {
                auto idx = std::lower_bound(subseq.begin(), subseq.end(), nums[i]) - subseq.begin();
                subseq[idx] = nums[i];
            }
        }

        return subseq.size();
    }

};