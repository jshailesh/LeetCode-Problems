// LC 40
// Given a collection of candidate numbers (candidates) and a target number (target), 
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combination_sum(std::vector<int>& combinations, int target) {
        _target = target;
        std::sort(combinations.begin(), combinations.end());
        dfs(combinations, 0, 0);
        return _result;
    }
    
private:
    int _target;
    std::vector<int> _slate;
    std::vector<std::vector<int>> _result;
    void dfs(std::vector<int>& combinations, int cidx, int csum) {
        if (csum >= _target) {
            if (_target == csum) {
                _result.emplace_back(_slate);
                return;
            }
        }

        if (cidx == combinations.size()) {
            return;
        }

        // Recursive Case:
        // Find the number of copies of the current element
        int ndups = 0;
        for (auto i = cidx; i < combinations.size(); ++i) {
            if (combinations[i] != combinations[cidx]) {
                break;
            }
            ++ndups;
        }

        // Exclusion Case: The current element is not included
        dfs(combinations, cidx + ndups, csum);

        // Multi-way inclusion
        for (auto i = 1; i <= ndups; ++i) {
            auto cnum = combinations[cidx];
            _slate.emplace_back(cnum);
            dfs(combinations, cidx + ndups, csum + i * cnum);
        }

        for (auto i = 0; i < ndups; ++i) {
            _slate.pop_back();
        }
    }
};