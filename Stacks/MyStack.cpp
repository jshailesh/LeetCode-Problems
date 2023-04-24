// LC 155
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

#include <vector>
#include <utility>

class MinStack {
private:
    std::vector<std::pair<int, int>> _data;

public:
    MinStack() = default;
    void push(int val) {
        if (_data.empty()) {
            _data.emplace_back(val, val);
        } else {
            auto minval = _data.back().second;
            if (val <= minval) {
                _data.emplace_back(val, val);
            } else {
                _data.emplace_back(val, minval);
            }
        }
    }

    void pop() {
        _data.pop_back();
    }

    int top() {
        return _data.back().first;
    }

    int getMin() {
        return _data.back().second;
    }
};