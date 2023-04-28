// // LC 424
// You are given a string s and an integer k. 
// You can choose any character of the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int characterReplacement(const std::string& s, int k) {
        int longest = 0;
        int left = 0;
        int most_freq_char = 0;
        std::unordered_map<char, int> char_count;
        for (auto i = 0; i < s.size(); ++i) {
            char c = s[i];
            char_count[c]++;
            most_freq_char = std::max(most_freq_char, char_count[c]);

            int window_len = i - left + 1; 
            if (window_len - most_freq_char > k) {
                char_count[s[left]]--;
                ++left;
            } else {
                longest = std::max(longest, i - left + 1);
            }
        }

        return longest;
    }

};