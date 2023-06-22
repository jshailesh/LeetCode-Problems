// LC 338
// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
// ans[i] is the number of 1's in the binary representation of i.

#include <vector>

class Solution {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> result(n + 1);
        result[0] = 0;
        for (auto i = 1; i <= n; ++i) {
            result[i] = result[i / 2] + i % 2;
        }

        return result;
    }
};