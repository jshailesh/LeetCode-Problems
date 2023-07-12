// LC 678
// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int cmin{0};
        int cmax{0};

        for (auto c : s) {
            if (c == '(') {
                ++cmin;
                ++cmax;
            } else if (c == ')') {
                --cmin;
                --cmax;
            } else {
                --cmin;
                ++cmax;
            }

            if (cmax < 0) {
                return false;
            }

            if (cmin < 0) {
                cmin = 0;
            }
        }

        return cmin == 0;
    }
};