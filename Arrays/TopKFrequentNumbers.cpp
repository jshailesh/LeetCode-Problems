#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> topKFrequentNumbers(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> nums_count;
        std::for_each(nums.begin(), nums.end(), [&nums_count] (auto num) {
            nums_count[num]++;
        });

        // Bucket Sort
        std::vector<int> buckets(nums.size() + 1);
        for (const auto& [value, count] : nums_count) {
            buckets[count].push_back(value);
        }
        std::reverse(buckets.begin(), buckets.end());

        std::vector<int> kfrequentNums;
        for (auto i = 0; i < buckets.size() && kfrequentNums.size() < k; ++i) {
            for (auto num : buckets[i]) {
                kfrequentNums.push_back(num);
                if (kfrequentNums.size() == k) {
                    return kfrequentNums;
                }
            }
        }

        return kfrequentNums;
    }

};