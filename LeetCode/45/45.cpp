#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Pure Recursion
    // Time: Exponential
    // Space: O(n) recursion stack
    int solveRecursive(vector<int>& nums, int n, int idx) {
        if (idx >= n - 1) {
            return 0;
        }
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n) {
                int jumps = solveRecursive(nums, n, idx + i);
                if (jumps != INT_MAX) {
                    minJumps = min(minJumps, 1 + jumps);
                }
            }
        }
        return minJumps;
    }
    // Approach 2: Recursion + Memoization
    // Time: O(n^2)
    // Space: O(n)
    int solveMemo(vector<int>& nums, int n, int idx,
                  vector<int>& dp) {
        if (idx >= n - 1) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            if (idx + i < n) {
                int jumps = solveMemo(nums, n, idx + i, dp);
                if (jumps != INT_MAX) {
                    minJumps = min(minJumps, 1 + jumps);
                }
            }
        }
        return dp[idx] = minJumps;
    }
    // Approach 3: Tabulation
    // Time: O(n^2)
    // Space: O(n)
    int solveTabulation(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int idx = n - 2; idx >= 0; idx--) {
            for (int j = 1; j <= nums[idx]; j++) {
                if (idx + j < n && dp[idx + j] != INT_MAX) {
                    dp[idx] = min(dp[idx], 1 + dp[idx + j]);
                }
            }
        }
        return dp[0];
    }
    // Approach 4: Greedy
    // Time: O(n)
    // Space: O(1)
    int solveGreedy(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                if (currentEnd >= n - 1) {
                    return jumps;
                }
            }
        }
        return jumps;
    }
public:
    int jumpRecursive(vector<int>& nums) {
        int n = nums.size();
        return solveRecursive(nums, n, 0);
    }
    int jumpMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solveMemo(nums, n, 0, dp);
    }
    int jumpTabulation(vector<int>& nums) {
        return solveTabulation(nums);
    }
    int jumpGreedy(vector<int>& nums) {
        return solveGreedy(nums);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {2, 3, 1, 1, 4},
        {2, 3, 0, 1, 4},
        {1, 1, 1, 1},
        {3, 2, 1, 0, 4},
        {0},
        {1, 2},
        {2, 1, 1, 1, 1}
    };
    cout << "JUMP GAME II - APPROACH COMPARISON\n";
    cout << "========================================\n";
    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];
        cout << "\nTest Case " << t + 1 << ": ";
        for (int x : nums) {
            cout << x << " ";
        }
        cout << "\n";
        // Pure recursion can be very slow for large inputs.
        cout << "Pure Recursion : "
             << sol.jumpRecursive(nums) << "\n";
        cout << "Memoization    : "
             << sol.jumpMemo(nums) << "\n";
        cout << "Tabulation     : "
             << sol.jumpTabulation(nums) << "\n";
        cout << "Greedy         : "
             << sol.jumpGreedy(nums) << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}
