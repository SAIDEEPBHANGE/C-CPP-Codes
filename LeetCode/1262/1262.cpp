#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Method to compute max sum divisible by 3
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        for (int x : nums) {
            vector<int> curr(dp);
            for (int r = 0; r < 3; r++) {
                int newSum = dp[r] + x;
                curr[newSum % 3] = max(curr[newSum % 3], newSum);
            }
            dp = curr;
        }
        return dp[0];
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    // Vector of test cases
    vector<vector<int>> testCases = {
        {3, 6, 5, 1, 8},
        {4},
        {1, 2, 3, 4, 4},
        {2, 2, 2, 2, 2},
        {7, 3, 9, 1, 2}
    };
    for (auto& test : testCases) {
        cout << sol.maxSumDivThree(test) << "\n";
    }
    return 0;
}