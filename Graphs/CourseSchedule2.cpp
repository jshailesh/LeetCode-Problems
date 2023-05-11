// LC 210
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
// take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. 
// If there are many valid answers, return any of them. 
// If it is impossible to finish all courses, return an empty array.

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        visited.resize(numCourses, -1);
        departure.resize(numCourses, -1);
        adj_list.resize(numCourses);

        for (const auto& prereq : prerequisites) {
            adj_list[prereq[1]].push_back(prereq[0]);
        }

        for (auto course = 0; course < numCourses; ++course) {
            if (visited[course] == -1) {
                if (dfs(course)) {
                    return {};
                }
            }
        }

        std::reverse(courses.begin(), courses.end());
        return courses;
    }

private:
    int time{0};
    std::vector<int> visited;
    std::vector<int> departure;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> courses;

    bool dfs(int course) {
        visited[course] = 1;
        for (const auto& prereq : adj_list[course]) {
            if (visited[prereq] == -1) {
                if (dfs(prereq)) {
                    visited[prereq] = 1;
                    return true;
                }
            } else if (departure[prereq] == -1) {
                return true;
            }
        }

        departure[course] = ++time;
        courses.push_back(course);
        return false;
    }
};