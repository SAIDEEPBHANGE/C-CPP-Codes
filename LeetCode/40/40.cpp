#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Backtracking (Without duplicate optimization)
    vector<vector<int>> ans1;
    void solveBrute(vector<int>& candidates, int target,
                    int start, vector<int>& temp) {
        if (target == 0) {
            ans1.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solveBrute(candidates, target - candidates[i],
                       i + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2Brute(
        vector<int>& candidates, int target) {
        ans1.clear();
        vector<int> arr = candidates;
        sort(arr.begin(), arr.end());
        vector<int> temp;
        solveBrute(arr, target, 0, temp);
        // Remove duplicate combinations
        sort(ans1.begin(), ans1.end());
        ans1.erase(unique(ans1.begin(), ans1.end()), ans1.end());
        return ans1;
    }
    // Approach 2: Optimized Backtracking (Skip duplicates)
    vector<vector<int>> ans2;
    void solveOptimized(vector<int>& candidates, int target,
                        int start, vector<int>& temp) {
        if (target == 0) {
            ans2.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            // Pruning because array is sorted
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            // Each element can be used only once
            solveOptimized(candidates, target - candidates[i],
                           i + 1, temp);
            // Backtracking
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2Optimized(
        vector<int>& candidates, int target) {
        ans2.clear();
        vector<int> arr = candidates;
        sort(arr.begin(), arr.end());
        vector<int> temp;
        solveOptimized(arr, target, 0, temp);
        return ans2;
    }
};
// Helper function to print combinations
void printResult(const string& approach,
                 vector<vector<int>> ans) {
    cout << approach << ":\n";
    if (ans.empty()) {
        cout << "No combinations found\n";
        return;
    }
    for (auto& combination : ans) {
        cout << "[ ";
        for (int num : combination)
            cout << num << " ";
        cout << "]\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<vector<int>, int>> testCases = {
        {{10, 1, 2, 7, 6, 1, 5}, 8},
        {{2, 5, 2, 1, 2}, 5},
        {{1, 1, 1, 1, 1}, 3},
        {{3, 4, 5}, 2},
        {{1, 2, 3}, 6}
    };
    Solution sol;
    for (int t = 0; t < testCases.size(); t++) {
        cout << "\n========== Test Case "
             << t + 1 << " ==========\n";
        vector<int> candidates = testCases[t].first;
        int target = testCases[t].second;
        cout << "Candidates: ";
        for (int num : candidates)
            cout << num << " ";
        cout << "\nTarget: " << target << "\n\n";
        auto brute = sol.combinationSum2Brute(
            candidates, target);
        auto optimized = sol.combinationSum2Optimized(
            candidates, target);
        printResult("Approach 1 - Brute Force", brute);
        printResult("Approach 2 - Optimized Backtracking", optimized);
    }
    return 0;
}
