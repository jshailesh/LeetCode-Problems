// LC
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

#include <vector>
#include <utility>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<std::pair<int, int>> zero_cells;
        int nrows = matrix.size();
        int ncols = matrix[0].size();

        for (int row = 0; row < nrows; ++row) {
            for (int col = 0; col < ncols; ++col) {
                if (matrix[row][col] == 0) {
                    zero_cells.emplace_back(row, col);
                }
            }
        }

        for (auto [row, col] : zero_cells) {
            for (int i = 0; i < ncols; ++i) {
                matrix[row][i] = 0;
            }

            for (int j = 0; j < nrows; ++j) {
                matrix[j][col] = 0;
            }
        }
    }
};