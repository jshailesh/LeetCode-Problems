// LC 42
// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(const std::vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int global_height = 0;
        int trapped_water = 0;

        while (left < right - 1) {
            auto current_max = std::min(heights[left], heights[right]);
            if (current_max > global_height) {
                // Excess Water
                trapped_water += (current_max - global_height) * (right - left - 1);
                global_height = current_max;
            }

            // Remove the water equivalent to the bar
            if (heights[left] <= heights[right]) {
                ++left;
                trapped_water -= std::min(heights[left], global_height);
            } else {
                --right;
                trapped_water -= std::min(heights[right], global_height);
            }
        }

        return trapped_water;
    }
};