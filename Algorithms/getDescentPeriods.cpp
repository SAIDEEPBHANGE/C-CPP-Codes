#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Optimized O(1) space solution
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 1;
        long long dp = 1;

        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - 1 == prices[i]) {
                dp += 1;
            } else {
                dp = 1;
            }
            ans += dp;
        }
        return ans;
    }

    // Method 2: DP array version (optional, same logic)
    long long getDescentPeriodsDP(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n, 1);
        long long ans = 1;

        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - 1 == prices[i]) {
                dp[i] = dp[i - 1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Vector of test cases
    vector<vector<int>> testCases = {
        {3, 2, 1, 4},
        {8, 6, 7, 7},
        {1},
        {5, 4, 3, 2, 1}
    };

    for (auto& prices : testCases) {
        cout << sol.getDescentPeriods(prices) << '\n';
    }

    return 0;
}
