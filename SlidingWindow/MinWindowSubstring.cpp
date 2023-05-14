// LC 76
// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

#include <cstddef>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int m = s.size();
        int n = t.size();
        
        std::unordered_map<char, int> tmap;
        std::for_each(t.begin(), t.end(), [&tmap] (char c) { tmap[c]++; });

        std::size_t start = 0;
        std::size_t end = 0;
        std::size_t min_start = 0;
        std::size_t min_length = m + 1;

        int nmatches = n;
        while (end < m) {
            if (tmap[s[end]] > 0) {
                nmatches--;
            }

            tmap[s[end]]--;
            ++end;

            while (nmatches == 0) {
                if (end - start < min_length) {
                    min_start = start;
                    min_length = end - start;
                }

                tmap[s[start]]++;

                if (tmap[s[start]] > 0) {
                    ++nmatches;
                }

                ++start;
            }

            if (min_length == m + 1) {
                return {};
            }

            return s.substr(min_start, min_length);
        }

    }
};