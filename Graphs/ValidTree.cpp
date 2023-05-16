// LC 261
// You have a graph of n nodes labeled from 0 to n - 1. 
// You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates 
// that there is an undirected edge between nodes ai and bi in the graph.

// Return true if the edges of the given graph make up a valid tree, and false otherwise.

#include <vector>
#include <numeric>

class Solution {
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        // A valid tree with n nodes need to have exactly n - 1 edges
        if (edges.size() != n - 1) {
            return false;
        }

        // Use the union-find algorithm to detect components
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);

        for (auto edge : edges) {
            auto root_first = find(edge[0]);
            auto root_second = find(edge[1]);

            if (root_first != root_second) {
                // the nodes belong to different components => more than one component
                return false;
            }

            parents[root_second] = root_first;
        }

        return true;
    }

private:
    std::vector<int> parents;
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }

        return parents[x] = find(parents[x]);
    }
};