// LC 853
// There are n cars going to the same destination along a one-lane road. The destination is target miles away.
// You are given two integer array position and speed, both of length n, where position[i] is the position of 
// the ith car and speed[i] is the speed of the ith car (in miles per hour).
// A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at 
// the same speed. The faster car will slow down to match the slower car's speed. The distance between 
// these two cars is ignored (i.e., they are assumed to have the same position).
// A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a 
// single car is also a car fleet.
// If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
// Return the number of car fleets that will arrive at the destination.

#include <vector>
#include <utility>
#include <algorithm>
#include <stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> car_status;
        for (auto i = 0; i < position.size(); ++i) {
            car_status.emplace_back(position[i], speed[i]);
        }

        std::sort(car_status.begin(), car_status.end());

        std::stack<double> monoQ;
        for (auto [pos, spd] : car_status) {
            double time_to_dst = static_cast<double> (target - pos) / spd;

            while (!monoQ.empty() && time_to_dst >= monoQ.top()) {
                monoQ.pop();
            }

            monoQ.emplace(time_to_dst);
        }

        return monoQ.size();
    }
};