// LC 973
// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, 
// return the k closest points to the origin (0, 0).
// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

#include <vector>
#include <priority_queue>

std::vector<std::vector<int>> kClosestPointsToOrigin(const std::vector<std::vector<int>>& points, int k) {
    std::vector<std::vector<int>> triples;
    for (const auto& p : points) {
        triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
    }

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> min_heap(
        triples.begin(), triples.end());

    std::vector<std::vector<int>> result;
    while (k > 0) {
        auto point = min_heap.top();
        min_heap.pop();
        --k;
        result.push_back(point[1], point[2]);
    }

    return result;
}