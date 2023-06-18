// LC 2
// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. 
// Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

#include "ListNode.hpp"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto sentinel = new ListNode;
        int csum = 0;
        auto current = sentinel;

        while (csum != 0 || l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                csum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                csum += l2->val;
                l2 = l2->next;
            }

            current->next = new ListNode(csum % 10);
            csum /= 10;
            current = current->next;
        }

        return sentinel->next;
    }
};