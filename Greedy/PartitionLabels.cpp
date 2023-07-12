// LC 763
// You are given a string s. We want to partition the string into as many parts as possible so
// that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> posn(26, 0);

        // Store the maximum index in the string s of the occurence of each character in it
        for (int i = 0; i < s.size(); ++i) {
            posn[s[i] - 'a'] = i;
        }

        // Now, sweep through the string again, and
        // Check the max index of the character
        // If the index exceeds the current index, that is partition
        std::vector<int> partitions;
        int idx{INT_MIN};
        int last_i{0};
        for (int i = 0; i < s.size(); ++i) {
            idx = std::max(idx, posn[s[i] - 'a']);
            if (idx == i) {
                partitions.push_back(i - std::exchange(last_i, i + 1) + 1);
            }
        }

        return partitions;
    }
};