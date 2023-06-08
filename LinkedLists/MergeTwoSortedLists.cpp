// LC 21
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

#include "ListNode.hpp"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // A Sentinel Node
        ListNode sentinel;
        ListNode* tail = &sentinel;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }

        if (list2 != nullptr) {
            tail->next = list2;
        }

        return sentinel.next;
    }
};