// LC 134
// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to 
// its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel 
// around the circuit once in the clockwise direction, otherwise return -1. 
// If there exists a solution, it is guaranteed to be unique

#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int start_at = 0;
        int total_surplus = 0;
        int surplus = 0;

        int nstations = gas.size();
        for (int iStn = 0; iStn < nstations; ++iStn) {
            auto local_usage = gas[iStn] - cost[iStn];
            total_surplus += local_usage;
            surplus += local_usage;

            // Not enough gas to get to this station starting from the 'start_at' station
            if (surplus < 0) {
                surplus = 0;
                start_at = iStn + 1;
            }
        }

        return total_surplus > 0 ? start_at : -1;
    }
};