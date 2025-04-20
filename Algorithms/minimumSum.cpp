#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute-force: O(n^3)
    int minimumSumBruteForce(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j] <= nums[i])
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (nums[j] <= nums[k])
                        continue;
                    int tempSum = nums[i] + nums[j] + nums[k];
                    result = min(result, tempSum);
                }
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
    // Optimized: O(n^2)
    int minimumSumOptimized(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        for (int j = 1; j < n - 1; j++) {
            int leftMin = INT_MAX;
            int rightMin = INT_MAX;
            // Find the minimum value on the left that is less than nums[j]
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j]) {
                    leftMin = min(leftMin, nums[i]);
                }
            }
            // Find the minimum value on the right that is less than nums[j]
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j]) {
                    rightMin = min(rightMin, nums[k]);
                }
            }
            if (leftMin != INT_MAX && rightMin != INT_MAX) {
                result = min(result, leftMin + nums[j] + rightMin);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};
int main() {
    Solution sol;
    // Vector of test cases (only the vector is needed, no diff)
    vector<vector<int>> testcases = {
        {8, 6, 1, 5, 3},        // Valid triplet: 1, 5, 3
        {1, 2, 3, 4, 5},        // No mountain triplet
        {5, 4, 3, 2, 1},        // No mountain triplet
        {2, 4, 1, 3, 5},        // Valid: 2, 4, 1
        {10, 1, 9, 2, 8, 3}     // Valid: 1, 9, 2 or others
    };
    for (int i = 0; i < testcases.size(); ++i) {
        vector<int> nums = testcases[i];
        int brute = sol.minimumSumBruteForce(nums);
        int optimized = sol.minimumSumOptimized(nums);
        cout << "Test Case " << i + 1 << ": ";
        for (int val : nums) cout << val << " ";
        cout << "\n";
        cout << "  Brute-force Result: " << brute << "\n";
        cout << "  Optimized Result  : " << optimized << "\n";
        cout << "-------------------------------------\n";
    }
    return 0;
}