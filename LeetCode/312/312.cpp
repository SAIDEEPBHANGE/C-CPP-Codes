#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Pure Recursion
    int solveRecursive(vector<int>& nums, int left, int right) {
        if (left > right) {
            return 0;
        }
        int maxi = 0;
        for (int i = left; i <= right; i++) {
            int coins = nums[left - 1] * nums[i] * nums[right + 1];
            coins += solveRecursive(nums, left, i - 1);
            coins += solveRecursive(nums, i + 1, right);
            maxi = max(maxi, coins);
        }
        return maxi;
    }
public:
    int maxCoinsRecursive(vector<int> nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solveRecursive(nums, 1, n);
    }
private:
    // Approach 2: Recursion + Memoization
    int solveMemo(vector<int>& nums, int left, int right,
                  vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int maxi = 0;
        for (int i = left; i <= right; i++) {
            int coins = nums[left - 1] * nums[i] * nums[right + 1];
            coins += solveMemo(nums, left, i - 1, dp);
            coins += solveMemo(nums, i + 1, right, dp);
            maxi = max(maxi, coins);
        }
        return dp[left][right] = maxi;
    }
public:
    int maxCoinsMemo(vector<int> nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solveMemo(nums, 1, n, dp);
    }
    // Approach 3: Tabulation (Bottom-Up DP)
    int maxCoinsTabulation(vector<int> nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int left = n; left >= 1; left--) {
            for (int right = left; right <= n; right++) {
                int maxi = 0;
                for (int i = left; i <= right; i++) {
                    int coins = nums[left - 1] *
                                nums[i] *
                                nums[right + 1];
                    coins += dp[left][i - 1];
                    coins += dp[i + 1][right];
                    maxi = max(maxi, coins);
                }
                dp[left][right] = maxi;
            }
        }
        return dp[1][n];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {3, 1, 5, 8},
        {1, 5},
        {7},
        {9, 76, 64, 21},
        {1, 2, 3, 4, 5}
    };
    cout << "Burst Balloons - Approach Comparison\n";
    cout << "====================================\n";
    for (int i = 0; i < testCases.size(); i++) {
        cout << "\nTest Case " << i + 1 << ": ";
        for (int x : testCases[i]) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "Pure Recursion       : "
             << sol.maxCoinsRecursive(testCases[i]) << "\n";
        cout << "Memoization          : "
             << sol.maxCoinsMemo(testCases[i]) << "\n";
        cout << "Tabulation           : "
             << sol.maxCoinsTabulation(testCases[i]) << "\n";
    }
    return 0;
}
