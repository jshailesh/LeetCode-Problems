// LC 11
// You are given an integer array height of length n. There are n vertical lines drawn such that the 
// two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

#include <vector>

int containerWithMostWater(const std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_water = 0;

    while (left < right) {
        max_water = max(max_water, min(height[left], height[right]) * (right - left));

        if (height[left] <= height[right]) {
            ++left;
        } else {
            --right;
        }
    }

    return max_water;
}