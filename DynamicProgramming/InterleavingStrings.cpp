// LC 97
// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings respectively, such that:
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

#include <string>
#include <vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        auto len_s1 = s1.size();
        auto len_s2 = s2.size();

        if (len_s1 + len_s2 != s3.size()) {
            return false;
        }

        std::vector<std::vector<bool>> table(len_s1 + 1, std::vector<bool> (len_s2 + 1));

        // Base Cases:
        // 1. All strings empty
        table[0][0] = true;

        // 2. s2 is an empty string, interleave s3 with s1
        for (auto i = 1; i <= len_s1; ++i) {
            if (table[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                table[i][0] = true;
            }
        }

        // 3. s1 is an empty string, interleave s3 with s2
        for (auto j = 1; j <= len_s2; ++j) {
            if (table[0][j - 1] && s2[j - 1] == s3[j - 1]) {
                table[0][j] = true;
            }
        }

        // For arbitrary i and j
        for (auto i = 1; i <= len_s1; ++i) {
            for (auto j = 1; j <= len_s2; ++j) {
                if ((table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                    table[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                        table[i][j] = true;
                }
            }
        }

        return table.back().back();
    }
};