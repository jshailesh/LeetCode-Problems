// LC 621
// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter 
// represents a different task. Tasks could be done in any order. Each task is done in one unit of time. 
// For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks 
// (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <pair>

class Solution {
public:
    int leastInterval(const std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> tasks_freq_map;
        std::for_each(tasks.begin(), tasks.end(), [&tasks_freq_map] (auto task) {
            tasks_freq_map[task]++;
        });

        using TaskInfo = std::pair<int, char>;
        std::priority_queue<TaskInfo> ordered_tasks;
        for (const auto& [task, freq] : tasks_freq_map) {
            ordered_tasks.emplace(freq, task);
        }

        int total_time = 0;
        while (!ordered_tasks.empty()) {
            std::vector<TaskInfo> tmp;
            int time = 0;
            for (auto idx = 0; idx <= n; ++idx) {
                if (!ordered_tasks.empty()) {
                    tmp.emplace_back(ordered_tasks.top());
                    ordered_tasks.pop();
                    ++time;
                }
            }

            for (auto [freq, task] : tmp) {
                --freq;
                if (freq > 0) {
                    ordered_tasks.emplace(freq, task);
                }
            }

            if (ordered_tasks.empty()) {
                total_time += time;
            } else {
                total_time += (n + 1);
            }
        }

        return total_time;
    }

};