// LC 138
// A linked list of length n is given such that each node contains an additional random pointer, 
// which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
// where each new node has its value set to the value of its corresponding original node. 
// Both the next and random pointer of the new nodes should point to new nodes in the copied list 
// such that the pointers in the original list and copied list represent the same list state. 
// None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
// then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. 
// Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
// or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

class Node {
public:
    int val;
    Node* next = nullptr;
    Node* random = nullptr;
    
    Node(int _val) : val(_val) {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Phase 1: Create a copy of each node. Have the next pointer of the node point to the copied node
        // Copied Node's next pointer points to the original next node of the node
        auto current = head;
        while (current != nullptr) {
            auto next_node = current->next;
            current->next = new Node(current->val);
            current->next->next = next_node;
            current = next_node;
        }

        // Update the random pointer of the copied node
        current = head;
        while (current != nullptr) {
            if (current->random != nullptr) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Tease the merged lists apart
        auto copied_head = head->next;
        current = head;
        while (current != nullptr) {
            auto next_node = copied_head->next;
            current->next = copied_head->next;
            copied_head->next = current->next->next;
            current = current->next;
        }

        return copied_head;
    }
}
