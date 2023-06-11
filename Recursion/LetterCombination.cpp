// LC 17
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations 
// that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. 
// Note that 1 does not map to any letters.

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }

        dfs_helper(0, digits);
        return result;
    }

private:
    std::unordered_map<char, std::string> numToLettersMap{
        {'0', ""},
        {'1', ""},
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    std::string slate;
    std::vector<std::string> result;
    void dfs_helper(int idx, const std::string& digits) {
        if (idx == digits.size()) {
            result.push_back(slate);
            return;
        }

        for (char digit : numToLettersMap[digits[idx]]) {
            slate.push_back(digit);
            dfs_helper(idx + 1, digits);
            slate.pop_back();
        }
    }

};