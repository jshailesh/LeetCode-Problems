// LC 66
// You are given a large integer represented as an integer array digits, where each digits[i] 
// is the ith digit of the integer. The digits are ordered from most significant to least 
// significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (digits.back() != 9) {
            digits.back()++;
            return digits;
        }

        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            if (*iter != 9) {
                *iter = *iter + 1;
                return digits;
            }
            *iter = 0;
        }

        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};