// LC 239
// You are given an array of integers nums, there is a sliding window of size k which is moving 
// from the very left of the array to the very right. You can only see the k numbers in the window. 
// Each time the sliding window moves right by one position.

// Return the max sliding window.

#include <vector>
#include <deque>
#include <utility>

class MonotonicQueue {
private:
    std::deque<std::pair<int, int>> monoQueue;

public:
    void push(int item) {
        int ndels;
        while (!monoQueue.empty() && item < monoQueue.back().first) {
            ndels += monoQueue.back().second + 1;
            monoQueue.pop_back();
        }
        monoQueue.emplace_back(item, ndels);
    }

    int max() const {
        return monoQueue.front().first;
    }

    void pop() {
        if (monoQueue.back().second > 0) {
            monoQueue.back().second--;
            return;
        }

        monoQueue.pop_back();
    }

};

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        MonotonicQueue myQ;

        for (auto i = 0; i < k - 1; ++i) {
            myQ.push(nums[i]);
        }

        std::vector<int> nearest;

        for (auto i = k - 1; i < nums.size(); ++i) {
            myQ.push(nums[i]);
            nearest.push_back(myQ.max());
            myQ.pop();
        }

        return nearest;
    }
};