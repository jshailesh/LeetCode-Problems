// LC 19
// Given the head of a linked list, remove the nth node from the end of the list and return its head.

#include "ListNode.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fast = head;

        while (n > 0) {
            fast = fast->next;
            --n;
        }

        if (fast == nullptr) {
            return head->next;
        }

        auto slow = head;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};