// LC 74
// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

#include <vector>

class Solution {
public: 
    bool search2DMatrix(const std::vector<std::vector>>& matrix, int target) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();

        int low = 0;
        int high = nrows * ncols - 1;

        while (low <= high) {
            auto mid = low + (high - low) / 2;

            auto mid_item = matrix[mid / ncols][mid % ncols];
            if (mid_item == target) {
                return true;
            } else if (mid_item > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }

};