// LC 143
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

#include "ListNode.hpp"
#include <stack>

class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        std::stack<ListNode *> nodes_reorder;
        while (slow != nullptr) {
            nodes_reorder.push(slow);
            slow = slow->next;
        }

        auto current = head;
        while (!nodes_reorder.empty()) {
            auto node = nodes_reorder.top();
            nodes_reorder.pop();

            if (current == node) {
                break;
            }

            auto tmp = current->next;
            current->next = node;
            node->next = tmp;
            current = tmp;
        }

        // Finally, make the next pointer of the last node in the reordered list to point to nullptr
        current->next = nullptr;
    }
};