#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) {
            return false;
        }
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
int main() {
    Solution sol;
    // Test case 1: [1, 5, 11, 5]
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Test case 1 result: " << (sol.canPartition(nums1) ? "True" : "False") << endl;
    // Test case 2: [1, 2, 3, 5]
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Test case 2 result: " << (sol.canPartition(nums2) ? "True" : "False") << endl;
    // Test case 3: [1, 2, 5]
    vector<int> nums3 = {1, 2, 5};
    cout << "Test case 3 result: " << (sol.canPartition(nums3) ? "True" : "False") << endl;
    // Test case 4: [2, 2, 1, 1]
    vector<int> nums4 = {2, 2, 1, 1};
    cout << "Test case 4 result: " << (sol.canPartition(nums4) ? "True" : "False") << endl;
    return 0;
}