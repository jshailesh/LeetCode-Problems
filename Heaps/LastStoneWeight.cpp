// LC 1046
// You are given an array of integers stones where stones[i] is the weight of the ith stone.
// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
// Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.
// Return the weight of the last remaining stone. If there are no stones left, return 0.

#include <queue>
#include <vector>

int lastStoneWeight(const std::vector<int>& stones) {
    std::priority_queue<int> max_heap(stones.begin(), stones.end());

    while (max_heap.size() > 1) {
        auto y = max_heap.top();
        max_heap.pop();

        auto x = max_heap.top();
        max_heap.pop();

        if (y != x) {
            max_heap.push(y - x);
        }
    }

    return (max_heap.empty() ? 0 : max_heap.top());
}