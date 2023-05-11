// LC 139
// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into 
// a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());

        // Here, table[i] is true if the substring s0s1...s(i - 1) can be broken down
        // into words in the dictionary
        std::vector<bool> table(s.size() + 1, false);

        // Empty String
        table[0] = true;

        for (auto i = 1; i <= s.size(); ++i) {
            for (auto j = 1; j <= i; ++j) {
                if (table[i - j] && dict.find(s.substr(i - j, j)) != dict.end()) {
                    table[i] = true;
                }
            }
        }

        return table.back();
    }
};