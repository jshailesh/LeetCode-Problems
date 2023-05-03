// LC 22
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include <vector>
#include <string>
#include <stack>
#include <tuple>

class SolutionRecursive {
public:
    std::vector<std::string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return _result;
    }

private:
    std::string _slate;
    std::vector<std::string> _result;
    void dfs(int n, int nopen, int nclose) {
        // Base Case:
        if (nopen == nclose && nopen == n) {
            _result.push_back(_slate);
            return;
        }

        // Recursive Case:
        if (nopen < n) {
            _slate.push_back('(');
            dfs(n, nopen + 1, nclose);
            _slate.pop_back();
        }

        if (nclose < nopen) {
            _slate.push_back(')');
            dfs(n, nopen, nclose + 1);
            _slate.pop_back();
        }
    }
};

class SolutionIterative {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::stack<std::tuple<std::string, int, int>> parens;
        parens.emplace("(", 1, 0);

        std::vector<std::string> results;
        while (!parens.empty()) {
            auto [current, nopen, nclose] = parens.top();
            parens.pop();

            if (nopen == nclose && nopen == n) {
                results.push_back(current);
                continue;
            }

            if (nopen < n) {
                parens.emplace(current + "(", nopen + 1, nclose);
            }

            if (nclose < nopen) {
                parens.emplace(current + ")", nopen, nclose + 1);
            }
        }

        return results;
    }

};