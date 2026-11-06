#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------------------------------
    // Approach 1: Brute Force O(n^2)
    // -------------------------------
    int maxRotateFunctionBrute(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        for (int k = 0; k < n; k++) {
            int curr = 0;
            for (int i = 0; i < n; i++) {
                curr += i * nums[(i - k + n) % n];
            }
            ans = max(ans, curr);
        }
        return ans;
    }

    // ------------------------------------------
    // Approach 2: Optimized using Recurrence O(n)
    // ------------------------------------------
    int maxRotateFunctionOptimized(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }

        long long result = F;

        for (int k = 1; k < n; k++) {
            F = F + sum - 1LL * n * nums[n - k];
            result = max(result, F);
        }

        return (int)result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {4, 3, 2, 6},
        {1, 2, 3, 4, 5},
        {10},
        {100, -1, -2, -3, -4},
        {0, 0, 0}
    };

    for (int t = 0; t < testCases.size(); t++) {
        vector<int> nums = testCases[t];

        cout << "Test Case " << t + 1 << ":\n";
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        int brute = sol.maxRotateFunctionBrute(nums);
        int optimized = sol.maxRotateFunctionOptimized(nums);

        cout << "Brute Force Result: " << brute << "\n";
        cout << "Optimized Result: " << optimized << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}