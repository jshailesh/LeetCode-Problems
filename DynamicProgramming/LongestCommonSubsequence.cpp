// LC: 1143
// Given two strings text1 and text2, return the length of their longest common subsequence. 
// If there is no common subsequence, return 0.
// A subsequence of a string is a new string generated from the original string with some characters 
// (can be none) deleted without changing the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        int m = text1.size();
        int n = text2.size();

        std::vector<std::vector<int>> table(m + 1, std::vector<int> (n + 1, 0));

        // Base Cases: first row and columns are all zeros
        // table[i][j] = longest common subsequence from x1x2...xi and y1y2...yj
        for (auto i = 1; i <= m; ++i) {
            for (auto j = 1; j <= n; ++j) {
                int match = (text1[i - 1] == text2[j - 1] ? 1 : 0);
                table[i][j] = std::max(table[i - 1][j - 1] + match,
                    std::max(table[i][j - 1], table[i - 1][j]));
            }
        }

        return table[m][n];
    }

};