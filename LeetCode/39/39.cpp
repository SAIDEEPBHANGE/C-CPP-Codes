#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Pure Recursion
    // Time: Exponential
    // Space: O(target / minCandidate) recursion stack
    void solveRecursive(vector<int>& candidates, int target, int idx,
                        vector<int>& current,
                        vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (idx >= candidates.size() || target < 0) {
            return;
        }
        // Pick the current element.
        // Same element can be picked again.
        if (candidates[idx] <= target) {
            current.push_back(candidates[idx]);
            solveRecursive(candidates, target - candidates[idx],
                           idx, current, ans);
            current.pop_back();
        }
        // Skip the current element.
        solveRecursive(candidates, target, idx + 1, current, ans);
    }
    // Approach 2: Backtracking
    // Time: Exponential (output-dependent)
    // Space: O(target / minCandidate) recursion stack
    void solveBacktracking(vector<int>& candidates, int target, int idx,
                           vector<int>& current,
                           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break;
            }
            current.push_back(candidates[i]);
            // Pass i instead of i + 1 because reuse is allowed.
            solveBacktracking(candidates, target - candidates[i],
                              i, current, ans);
            current.pop_back();
        }
    }
public:
    // Approach 1: Pick / Not Pick
    vector<vector<int>> combinationSumRecursive(
        vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solveRecursive(candidates, target, 0, current, ans);
        return ans;
    }
    // Approach 2: Optimized Backtracking
    vector<vector<int>> combinationSumBacktracking(
        vector<int>& candidates, int target) {
        vector<int> nums = candidates;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        solveBacktracking(nums, target, 0, current, ans);
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<pair<vector<int>, int>> testCases = {
        {{2, 3, 6, 7}, 7},
        {{2, 3, 5}, 8},
        {{2}, 1},
        {{1}, 4},
        {{2, 4, 6}, 8},
        {{3, 4, 5}, 12}
    };
    auto printResults = [](const vector<vector<int>>& ans) {
        cout << "[\n";
        for (const auto& combination : ans) {
            cout << "  [";
            for (int i = 0; i < combination.size(); i++) {
                cout << combination[i];
                if (i + 1 < combination.size()) {
                    cout << ", ";
                }
            }
            cout << "]\n";
        }
        cout << "]\n";
    };
    cout << "COMBINATION SUM - APPROACH COMPARISON\n";
    cout << "========================================\n";
    for (int t = 0; t < testCases.size(); t++) {
        vector<int> candidates = testCases[t].first;
        int target = testCases[t].second;
        cout << "\nTest Case " << t + 1 << "\n";
        cout << "Candidates: ";
        for (int x : candidates) {
            cout << x << " ";
        }
        cout << "\nTarget: " << target << "\n";
        cout << "\nApproach 1: Pure Recursion\n";
        auto ans1 = sol.combinationSumRecursive(candidates, target);
        printResults(ans1);
        cout << "\nApproach 2: Backtracking\n";
        auto ans2 = sol.combinationSumBacktracking(candidates, target);
        printResults(ans2);
        cout << "----------------------------------------\n";
    }
    return 0;
}
