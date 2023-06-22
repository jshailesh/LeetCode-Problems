// LC 846
// Alice has some number of cards and she wants to rearrange the cards into groups 
// so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card 
// and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        std::map<int, int> hand_count;
        for (auto val : hand) {
            hand_count[val]++;
        }

        while (!hand_count.empty()) {
            auto curr = hand_count.begin()->first;
            for (auto i = 1; i < groupSize; ++i) {
                if (hand_count.count(curr + i) == 0) {
                    return false;
                }
                hand_count[curr]--;
                if (hand_count[curr] == 0) {
                    hand_count.erase(curr);
                }
            }
        }

        return true;
    }
};