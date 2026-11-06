#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 1, num = -1;
        vector<int> v;
        // Sorting the input array
        cout << "Original nums: ";
        for (int num : nums) cout << num << " ";
        cout << endl;
        sort(nums.begin(), nums.end());
        cout << "Sorted nums: ";
        for (int num : nums) cout << num << " ";
        cout << endl;
        vector<int> dp(n, 1);
        // DP computation to find the largest divisible subset
        cout << "DP computation:" << endl;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (!(nums[i] % nums[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    if (maxi < dp[i]) {
                        maxi = dp[i];
                    }
                }
            }
            cout << "dp[" << i << "] = " << dp[i] << endl;
        }
        // Finding the largest divisible subset by backtracking
        cout << "Reconstructing the subset:" << endl;
        for (int i = n - 1; i >= 0; i--) {
            cout << "Checking dp[" << i << "] = " << dp[i] << " with maxi = " << maxi << endl;
            if (maxi == dp[i] && (num == -1 || !(num % nums[i]))) {
                cout << "Adding " << nums[i] << " to the result." << endl;
                v.push_back(nums[i]);
                maxi--;
                num = nums[i];
            }
        }
        // Final result
        cout << "Largest Divisible Subset: ";
        for (int num : v) cout << num << " ";
        cout << endl;
        return v;
    }
};
int main() {
    Solution solution;
    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test case 1: {1, 2, 3}" << endl;
    vector<int> result1 = solution.largestDivisibleSubset(nums1);
    cout << "\n--------------------------------------------------\n" << endl;
    // Test case 2
    vector<int> nums2 = {1, 2, 4, 8};
    cout << "Test case 2: {1, 2, 4, 8}" << endl;
    vector<int> result2 = solution.largestDivisibleSubset(nums2);
    cout << "\n--------------------------------------------------\n" << endl;
    return 0;
}