// LC 323
// You have a graph of n nodes. You are given an integer n and an array edges
//  where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

// Return the number of connected components in the graph.

#include <vector>
#include <numeric>

class Solution {
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
        ncomponents = n;

        for (auto edge : edges) {
            auto parent_first = edge[0];
            auto parent_second = edge[1];
            if (parent_first != parent_second) {
                parents[parent_second] = parent_first;
                --ncomponents;
            }
        }

        return ncomponents;
    }

private:
    int ncomponents;
    std::vector<int> parents;

    int find_parent(int node) {
        if (parents[node] == node) {
            return node;
        }

        return parents[node] = find_parent(parents[node]);
    }
};