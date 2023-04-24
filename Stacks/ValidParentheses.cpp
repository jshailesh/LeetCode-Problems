// LC 20
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.

#include <string>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(const std::string& s) {
        for (auto paren : s) {
            if (paren_complement.find(paren) != paren_complement.end()) {
                if (parens.empty() || parens.top() != paren_complement[paren]) {
                    return false;
                }
                parens.pop();
            } else {
                parens.push(paren);
            }
        }

        return parens.empty();
    }
private:
    const static std::unordered_map<char, char> paren_complement{
        {')', '('},
        {'}', '{'},
        {']', '['}};
    std::stack<char> parens;
};
