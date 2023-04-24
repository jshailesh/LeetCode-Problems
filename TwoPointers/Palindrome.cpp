// LC 125
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
// removing all non-alphanumeric characters, it reads the same forward and backward. 
// Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

#include <string>
#include <cctype>

bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        while (left < right && !std::isalnum(s[left])) {
            ++left;
        }

        while (right > left && !std::isalnum(s[right])) {
            --right;
        }

        if (std::tolower(s[left]) != std::lower(s[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}