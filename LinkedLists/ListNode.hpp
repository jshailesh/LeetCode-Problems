#pragma once

struct ListNode {
    int val = 0;
    ListNode *next = nullptr;
    
    ListNode() = default;
    ListNode(int x) : val(x) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};