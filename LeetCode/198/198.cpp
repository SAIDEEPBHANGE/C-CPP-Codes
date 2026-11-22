#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^n), Space: O(n) recursion stack
    int robRecursiveHelper(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        int robCurrent = nums[i] + robRecursiveHelper(nums, i + 2);
        int skipCurrent = robRecursiveHelper(nums, i + 1);
        return max(robCurrent, skipCurrent);
    }
    int robRecursive(vector<int>& nums) {
        return robRecursiveHelper(nums, 0);
    }
    // Approach 2: Recursion + Memoization (Top-Down DP)
    // Time: O(n), Space: O(n)
    int robMemoHelper(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int robCurrent = nums[i] + robMemoHelper(nums, i + 2, dp);
        int skipCurrent = robMemoHelper(nums, i + 1, dp);
        return dp[i] = max(robCurrent, skipCurrent);
    }
    int robMemoization(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robMemoHelper(nums, 0, dp);
    }
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(n), Space: O(n)
    int robTabulation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
        }
        return dp[n];
    }
    // Approach 4: Space Optimized DP
    // Time: O(n), Space: O(1)
    int robOptimized(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 0; i < n; i++) {
            int current = max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {2, 1, 1, 2},
        {5},
        {10, 5},
        {6, 7, 1, 30, 8, 2, 4}
    };
    cout << "House Robber - Approach Comparison\n";
    cout << "===================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        vector<int>& nums = testCases[i];
        cout << "Test Case " << i + 1 << ": ";
        cout << "[";
        for (int j = 0; j < nums.size(); j++) {
            cout << nums[j];
            if (j != nums.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
        cout << "Recursive       : "
             << sol.robRecursive(nums) << "\n";
        cout << "Memoization     : "
             << sol.robMemoization(nums) << "\n";
        cout << "Tabulation      : "
             << sol.robTabulation(nums) << "\n";
        cout << "Space Optimized : "
             << sol.robOptimized(nums) << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}