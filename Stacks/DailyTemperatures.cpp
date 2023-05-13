// LC 739
// Given an array of integers temperatures represents the daily temperatures, return an array 
// answer such that answer[i] is the number of days you have to wait after the ith day to get 
// a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include <vector>
#include <stack>
#include <utility>

class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        int ndays = temperatures.size();
        std::vector<int> answer(ndays, 0);

        // Stack: holds temperature and the day number
        // Initialize it with the first day values
        std::stack<std::pair<int, int>> tstack;
        tstack.emplace(temperatures.front(), 0);

        for (auto day = 1; day < ndays; ++day) {
            int temp_today = temperatures[day];
            while (!tstack.empty() && tstack.top().first < temp_today) {
                int myday = tstack.top().second;
                answer[myday] = day - myday;
                tstack.pop();
            }

            tstack.emplace(temp_today, day);
        }

        // Are there items still in stack? Those days did not see
        // higher temperatures after them
        while (!tstack.empty()) {
            answer[tstack.top().second] = 0;
            tstack.pop();
        }

        return answer;
    }

};