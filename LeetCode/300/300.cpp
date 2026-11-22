#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Dynamic Programming (Bottom-Up)
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    int lengthOfLIS_DP(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // Approach 2: Binary Search (Patience Sorting)
    // Time Complexity: O(n log n)
    // Space Complexity: O(n)
    int lengthOfLIS_BinarySearch(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
    // Approach 3: Recursive + Memoization
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    int solve(int index, int prevIndex, vector<int>& nums,
              vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][prevIndex + 1] != -1) {
            return dp[index][prevIndex + 1];
        }
        // Option 1: Skip current element
        int notTake = solve(index + 1, prevIndex, nums, dp);
        // Option 2: Take current element
        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
            take = 1 + solve(index + 1, index, nums, dp);
        }
        return dp[index][prevIndex + 1] = max(take, notTake);
    }
    int lengthOfLIS_Memoization(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, nums, dp);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {7, 7, 7, 7, 7, 7, 7},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1},
        {},
        {3, 10, 2, 1, 20},
        {1, 3, 6, 7, 9, 4, 10, 5, 6}
    };
    int testNumber = 1;
    for (auto nums : testCases) {
        // Each approach receives the same input.
        vector<int> arr1 = nums;
        vector<int> arr2 = nums;
        vector<int> arr3 = nums;
        int resultDP = sol.lengthOfLIS_DP(arr1);
        int resultBinary = sol.lengthOfLIS_BinarySearch(arr2);
        int resultMemo = sol.lengthOfLIS_Memoization(arr3);
        cout << "Test Case " << testNumber++ << ":\n";
        cout << "Input: ";
        for (int num : nums) {
            cout << num << " ";
        }
        if (nums.empty()) {
            cout << "(empty)";
        }
        cout << "\n";
        cout << "Approach 1 - DP:             " << resultDP << "\n";
        cout << "Approach 2 - Binary Search:  " << resultBinary << "\n";
        cout << "Approach 3 - Memoization:    " << resultMemo << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}