// LC 36
// Determine if a 9 x 9 Sudoku board is valid. 
// Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool validSudoku(const std::vector<std::vector<char>>& board) {
        int nrows = board.size();
        std::vector<std::unordered_set<char>> rows_set(nrows), cols_set(nrows), zones_set(nrows);

        for (auto row = 0; row < nrows; ++row) {
            for (auto col = 0; col < nrows; ++col) {
                auto num = board[row][col];
                auto zone = (row / 3) * 3 + col / 3;
                if (rows_set[row].count(num) == 1 || 
                    cols_set[col].count(num) == 1 || 
                    zones_set[zone].count(num) == 1) {
                    return false;
                }
                rows_set[row].emplace(num);
                cols_set[col].emplace(num);
                zones_set[zone].emplace(num);
            }
        }
        return true;
    }

};