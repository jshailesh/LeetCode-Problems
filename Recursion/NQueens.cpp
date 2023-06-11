// LC 51
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that 
// no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. 
// You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, 
// where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        dfs_helper(board, 0);
        return result;
    }

private:
    std::unordered_set<int> cols, left_diag, right_diag;
    std::vector<std::vector<std::string>> result;
    bool isSafe(std::vector<std::string>& board, int x, int y) {
        // Same column
        if (cols.find(y) != cols.end()) {
            return false;
        }

        // Left Diagonal above
        if (left_diag.find(x - y) != left_diag.end()) {
            return false;
        }

        // Right Diagnoal above
        if (right_diag.find(x + y) != right_diag.end()) {
            return false;
        }
        return true;
    }

    void dfs_helper(std::vector<std::string>& board, int row) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                cols.insert(col);
                left_diag.insert(row - col);
                left_diag.insert(row + col);
                dfs_helper(board, row + 1);
                board[row][col] = '.';
                cols.erase(col);
                left_diag.erase(row - col);
                right_diag.erase(row + col);
            }
        }
    }
};