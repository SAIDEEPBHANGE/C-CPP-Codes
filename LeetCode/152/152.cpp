#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Brute Force
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    int maxProductBruteForce(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        for (int i = 0; i < n; i++) {
            int currProduct = 1;
            for (int j = i; j < n; j++) {
                currProduct *= nums[j];
                result = max(result, currProduct);
            }
        }
        return result;
    }
    // Approach 2: Prefix and Suffix Product
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int maxProductPrefixSuffix(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int result = INT_MIN;
        for (int i = 0; i < n; i++) {
            // Reset product after encountering zero.
            if (prefix == 0) {
                prefix = 1;
            }
            if (suffix == 0) {
                suffix = 1;
            }
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            result = max(result, max(prefix, suffix));
        }
        return result;
    }
    // Approach 3: Dynamic Programming (Kadane's Algorithm)
    // Track both maximum and minimum products.
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int maxProductDP(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            // Negative number swaps maximum and minimum.
            if (num < 0) {
                swap(currMax, currMin);
            }
            currMax = max(num, currMax * num);
            currMin = min(num, currMin * num);
            result = max(result, currMax);
        }
        return result;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution solution;
    // Hardcoded test cases.
    vector<vector<int>> testCases = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {0, 2},
        {-2},
        {2, -5, -2, -4, 3},
        {-1, -2, -3, -4},
        {1, 2, 3, 4},
        {-2, 0, -3, 4, -1},
        {0, 0, 0}
    };
    cout << "Maximum Product Subarray - Approach Comparison\n";
    cout << "================================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        // Create separate copies for each approach.
        vector<int> arr1 = nums;
        vector<int> arr2 = nums;
        vector<int> arr3 = nums;
        int bruteForce = solution.maxProductBruteForce(arr1);
        int prefixSuffix = solution.maxProductPrefixSuffix(arr2);
        int dynamicProgramming = solution.maxProductDP(arr3);
        cout << "Test Case " << i + 1 << ": ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "\n";
        cout << "Brute Force       : " << bruteForce << "\n";
        cout << "Prefix/Suffix     : " << prefixSuffix << "\n";
        cout << "Dynamic Programming: " << dynamicProgramming << "\n";
        cout << "------------------------------------------------\n";
    }
    return 0;
}