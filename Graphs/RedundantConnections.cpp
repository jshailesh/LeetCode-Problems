// LC 684
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one 
// additional edge added. The added edge has two different vertices chosen from 1 to n, and 
// was not an edge that already existed. The graph is represented as an array edges of length 
// n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
// If there are multiple answers, return the answer that occurs last in the input.

#include <vector>
#include <numeric>

class UnionFind {
public:
    explicit UnionFind(int n) {
        parents.resize(n);
        std::iota(parents.begin(), parents.end(), 0);
        ranks.resize(n, 1);
    }

    bool do_union(int x, int y) {
        auto root_x = find(x);
        auto root_y = find(y);

        if (root_x == root_y) {
            return false;
        }

        if (ranks[root_x] >= ranks[root_y]) {
            ranks[root_x] += ranks[root_y];
            parents[root_y] = root_x;
        } else {
            ranks[root_y] += ranks[root_x];
            parents[root_x] = root_y;
        }

        return true;
    }

private:
    std::vector<int> parents, ranks;
    int find(int x) {
        if (x == parents[x]) {
            return x;
        }

        return parents[x] = find(parents[x]);
    }
};

class Solution {
private:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        UnionFind myUnionFind(edges.size());
        for (auto edge : edges) {
            if (!myUnionFind.do_union(edge[0] - 1, edge[1] - 1)) {
                return {edge[0], edge[1]};
            }
        }

        return {};
    }

};