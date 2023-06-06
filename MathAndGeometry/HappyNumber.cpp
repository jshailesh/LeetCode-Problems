// LC
// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly 
// in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> numbers;
        while (n != 1 && numbers.count(n) != 1) {
            numbers.insert(n);
            int sum_of_sqs = 0;
            while (n != 0) {
                int right = n % 10;
                sum_of_sqs += (right * right);
                n /= 10;
            }

            n = sum_of_sqs;
        }

        return n == 1;
    }
};