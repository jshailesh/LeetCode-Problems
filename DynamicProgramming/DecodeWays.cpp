// LC 91
// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the 
// reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The test cases are generated so that the answer fits in a 32-bit integer.

#include <string>
#include <vector>

class Solution {
public:
    int decodeWays(const std::string& s) {
        if (s[0] == '0') {
            return 0;
        }

        std::vector<int> table(s.size() + 1, 0);

        // Empty String - Assume
        table[0] = 1;
        table[1] = 1; // We have an early return if the first char is a '0'

        for (auto i = 2; i <= s.size(); ++i) {
            if (s[i - 1] != '0') {
                table[i] += table[i - 1];
            }

            if (s[i - 2] == '1' || (s[i - 2] == '2' && (s[i - 1] != '7' && s[i - 1] != '8' && s[i - 1] != '9'))) {
                table[i] += table[i - 2];
            }
        }

        return table.back();
    }
};