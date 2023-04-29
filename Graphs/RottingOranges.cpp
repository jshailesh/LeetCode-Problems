// LC 994
// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include <vector>
#include <utility>
#include <queue>

class Solution {
public: 
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        nrows = grid.size();
        ncols = grid[0].size();
        int fresh = 0;
        for (auto row = 0; row < nrows; ++row) {
            for (auto col = 0; col < ncols; ++col) {
                if (grid[row][col] == 2) {
                    rotten_oranges.emplace(row, col);
                }

                if (grid[row][col] == 1) {
                    ++fresh;
                }
            }
        }

        int minutes = 0;
        while (fresh > 0 && !rotten_oranges.empty()) {
            auto num_rotten = rotten_oranges.size();
            for (auto i = 0; i < num_rotten; ++i) {
                auto [cx, cy] = rotten_oranges.front();
                rotten_oranges.pop();
                for (auto [nx, ny] : get_neighbors(cx, cy)) {
                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        --fresh;
                        rotten_oranges.emplace(nx, ny);
                    }
                }
            }

            ++minutes;
        }

        if (fresh > 0) {
            return -1;
        }

        return minutes;
    }

private:
    int nrows;
    int ncols;

    using Cell = std::pair<int, int>;
    using ListOfCells = std::vector<Cell>;

    std::queue<Cell> rotten_oranges;

    ListOfCells get_neighbors(int x, int y) {
        ListOfCells neighbors;
        if (x - 1 >= 0) {
            neighbors.emplace_back(x - 1, y);
        }

        if (x + 1 < nrows) {
            neighbors.emplace_back(x + 1, y);
        }

        if (y - 1 >= 0) {
            neighbors.emplace_back(x, y - 1);
        }

        if (y + 1 < ncols) {
            neighbors.emplace_back(x, y + 1);
        }

        return neighbors;
    }

};