#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Pure Recursion
    // Time: Exponential, Space: O(n) recursion stack
    bool solveRecursive(vector<int>& nums, int n, int idx) {
        if (idx == n - 1) {
            return true;
        }
        if (idx >= n) {
            return false;
        }
        int jumpLen = nums[idx];
        for (int i = 1; i <= jumpLen; i++) {
            if (solveRecursive(nums, n, idx + i)) {
                return true;
            }
        }
        return false;
    }
    // Approach 2: Greedy
    // Time: O(n), Space: O(1)
    bool solveGreedy(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;
            }
        }
        return true;
    }
    // Approach 3: Recursion + Memoization
    // Time: O(n^2), Space: O(n)
    bool solveMemo(vector<int>& nums, int n, int idx,
                   vector<int>& dp) {
        if (idx >= n - 1) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int jumpLen = nums[idx];
        for (int i = 1; i <= jumpLen; i++) {
            if (solveMemo(nums, n, idx + i, dp)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
public:
    bool canJumpRecursive(vector<int>& nums) {
        int n = nums.size();
        return solveRecursive(nums, n, 0);
    }
    bool canJumpGreedy(vector<int>& nums) {
        return solveGreedy(nums);
    }
    bool canJumpMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solveMemo(nums, n, 0, dp);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},
        {3, 2, 1, 0, 4},
        {2, 0, 0},
        {0},
        {1, 1, 1, 1},
        {2, 5, 0, 0},
        {1, 0, 1, 0}
    };
    cout << "JUMP GAME - APPROACH COMPARISON\n";
    cout << "========================================\n";
    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];
        bool recursive = sol.canJumpRecursive(nums);
        bool greedy = sol.canJumpGreedy(nums);
        bool memo = sol.canJumpMemo(nums);
        cout << "\nTest Case " << t + 1 << ": ";
        for (int x : nums) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "Pure Recursion       : "
             << (recursive ? "true" : "false") << "\n";
        cout << "Greedy               : "
             << (greedy ? "true" : "false") << "\n";
        cout << "Memoization          : "
             << (memo ? "true" : "false") << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}
