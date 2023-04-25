// LC 150
// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        for (auto token : tokens) {
            if (operation_map.find(token) != operation_map.end()) {
                auto second = operands.top();
                operands.pop();
                auto first = operands.top();
                operands.pop();
                operands.push(operation_map[token] (first, second));
            } else {
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
private:
    std::stack<int> operands;
    std::unordered_map<std::string, function<int(int, int)>> operation_map{
        {"+", [] (int x, int y) { return x + y; }},
        {"-", [] (int x, int y) { return x - y; }},
        {"*", [] (int x, int y) { return x * y; }},
        {"/", [] (int x, int y) { return x / y; }}};
};