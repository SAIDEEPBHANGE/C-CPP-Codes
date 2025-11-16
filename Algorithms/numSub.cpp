#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const long long MOD = 1e9 + 7;
public:
    // --- Method 1: DP Version ---
    int numSub_DP(const string &s) {
        int n = s.size();
        vector<long long> dp(n, 0);
        dp[0] = (s[0] == '1' ? 1 : 0);
        long long sum = dp[0];
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i] = dp[i - 1] + 1;
            }
            sum = (sum + dp[i]) % MOD;
        }
        return sum;
    }
    // --- Method 2: Optimized O(n) Version ---
    int numSub_Optimized(const string &s) {
        long long result = 0, count = 0;
        for (char c : s) {
            if (c == '1') {
                count++;
                result = (result + count) % MOD;
            } else {
                count = 0;
            }
        }
        return result;
    }
};
int main() {
    vector<string> testCases = {
        "111111",
        "1010111",
        "0000",
        "1",
        "110011100111"
    };
    Solution sol;
    for (const string &s : testCases) {
        cout << "String: " << s << "\n";
        cout << "DP Method:         " << sol.numSub_DP(s) << "\n";
        cout << "Optimized Method:  " << sol.numSub_Optimized(s) << "\n";
        cout << "----------------------------\n";
    }
    return 0;
}