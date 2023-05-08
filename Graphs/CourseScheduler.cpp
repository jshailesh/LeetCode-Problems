// LC 207
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
// take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        visited.resize(numCourses, -1);
        departure.resize(numCourses, -1);
        adj_list.resize(numCourses);

        for (const auto& prereq : prerequisites) {
            adj_list[prereq[0]].push_back(prereq[1]);
        }

        for (int course = 0; course < numCourses; ++course) {
            if (visited[course] == -1) {
                if (dfs(course)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    int time = 0;
    std::vector<int> visited;
    std::vector<int> departure;
    std::vector<std::vector<int>> adj_list;
    bool dfs(int course) {
        // Mark the course as visited
        visited[course] = 1;

        for (const auto& prereq : adj_list[course]) {
            if (visited[prereq] == -1) {
                if (dfs(prereq)) {
                    return true;
                }
            } else if (departure[prereq] == -1) {
                return true;
            }
        }

        departure[course] = time++;
        return false;
    }
};