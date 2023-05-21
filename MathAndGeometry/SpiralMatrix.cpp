// LC 54
// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();

        // pointer to track movement
        int left = 0, right = ncols - 1;
        int top = 0, bottom = nrows - 1;

        // Directions
        enum class dirs { right, down, left, up };
        dirs next = dirs::right;

        std::vector<int> result;
        while (left <= right && top <= bottom) {
            if (dirs::right == next) {
                for (int i = left; i <= right; ++i) {
                    result.push_back(matrix[top][i]);
                    next = dirs::down;
                    ++top;
                }
            } else if (dirs::down == next) {
                for (int i = top; i <= bottom; ++i) {
                    result.push_back(matrix[i][right]);
                    next = dirs::left;
                    --right;
                }
            } else if (dirs::left == next) {
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                    next = dirs::up;
                    --bottom;
                }
            } else if (dirs::up == next) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                    next = dirs::right;
                    ++left;
                }
            }
        }

        return result;
    }
};