// LC 875

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
// The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. 
// Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

#include <algorithm>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int speed = 1;

        while (low <= high) {
            int mid_speed = low + (high - low) / 2;
            auto total_time = getTotalTimeToEatAllBananas(piles, mid_speed);

            if (total_time <= h) {
                // Koko is under the time limit; can Koko eat in less time?
                speed = mid_speed;
                high = mid_speed - 1;
            } else {
                // The speed was not sufficient and so try a higher speed
                low = mid_speed + 1;
            }
        }

        return speed;
    }

private:
    long getTotalTimeToEatAllBananas(const std::vector<int>& piles, int speed) {
        long total_time = 0;
        for (auto pile : piles) {
            total_time += std::ceil(static_cast<double> (pile) / speed);
        }
        return total_time;
    }
};