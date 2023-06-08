// LC 206
// Reverse a Linked List

#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};