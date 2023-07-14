// LC 25
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k, then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

#include "ListNode.hpp"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto sentinel = new ListNode(0, head);
        auto current = head;
        auto predecessor = sentinel;

        // Scan the linked list k times: finds the head of the next k-group
        // This becomes the terminating node for the current k-group
        auto tmp = current;
        for (int i = 0; i < k; ++i) {
            if (tmp == nullptr) {
                return sentinel->next;
            }

            tmp = tmp->next;
        }

        // tmp now points to the head of the next k-group
        // Reverse the current k-group
        ListNode* kGrpPred = nullptr;
        auto kGrpCurrent = current;
        while (kGrpCurrent != tmp) {
            auto successor = kGrpCurrent->next;
            kGrpCurrent->next = kGrpPred;
            kGrpPred = kGrpCurrent;
            kGrpCurrent = successor;
        }

        // Update the tail of the previous k-group to point to the current k-group head
        predecessor->next = kGrpPred;
        current->next = kGrpCurrent;

        // Update the current and predecessor for the next iteration
        predecessor = current;
        current = current->next;

        return sentinel->next;
    }
};