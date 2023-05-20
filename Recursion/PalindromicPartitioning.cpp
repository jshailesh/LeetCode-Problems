// LC 131
// Given a string s, partition s such that every substring of the partition is a 
// palindrome. Return all possible palindrome partitioning of s.

#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        partition_helper(s, 0);
        return result;
    }

private:
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> slate;
    bool isPalindrome(const std::string& aStr, int start, int end) {
        while (start < end) {
            if (aStr[start] != aStr[end]) {
                return false;
            }

            ++start;
            --end;
        }

        return true;
    }

    void partition_helper(const std::string& s, int startIdx) {
        // Base Case:
        if (startIdx == s.size()) {
            result.push_back(slate);
            return;
        }

        // Recursive Case:
        for (auto end = startIdx; end < s.size(); ++end) {
            if (isPalindrome(s, startIdx, end)) {
                slate.push_back(s.substr(startIdx, end - startIdx + 1));
                partition_helper(s, end + 1);
                slate.pop_back();
            }
        }
    }
};