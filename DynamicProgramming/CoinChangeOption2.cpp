// LC 518
// You are given an integer array coins representing coins of different denominations 
// and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

#include <vector>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int ncoins = coins.size();
        std::vector<int> table(ncoins + 1, 0);

        // Base Case: 1 way to get an amount of 0
        table[0] = 1;

        for (auto coin : coins) {
            for (auto val = 1; val <= amount; ++val) {
                if (auto diff_amt = val - coin; diff_amt >= 0) {
                    table[val] += table[diff_amt];
                }
            }
        }

        return table[amount];
    }

};