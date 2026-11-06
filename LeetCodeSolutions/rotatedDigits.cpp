#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // -------------------- Approach 1: Brute Force --------------------
    bool isGood(int num) {
        bool changed = false;
        while (num > 0) {
            int digit = num % 10;
            // Invalid digits
            if (digit == 3 || digit == 4 || digit == 7) return false;
            // Digits that change
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                changed = true;
            num /= 10;
        }
        return changed;
    }
    int rotatedDigits_Brute(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }
        return count;
    }
    // -------------------- Approach 2: DP (Digit Classification) --------------------
    int rotatedDigits_DP(int n) {
        vector<int> dp(n + 1, 0);
        // 0 = invalid, 1 = valid same, 2 = good (valid + changed)
        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2;
                    if (i != 0) count++;
                } else dp[i] = 0;
            } else {
                int a = dp[i / 10];
                int b = dp[i % 10];
                if (a == 1 && b == 1) dp[i] = 1;
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2;
                    count++;
                } else dp[i] = 0;
            }
        }
        return count;
    }
    // -------------------- Approach 3: Digit DP --------------------
    int digitDP(int pos, bool tight, bool changed, string &s, vector<vector<vector<int>>> &dp) {
        if (pos == s.size()) return changed ? 1 : 0;
        if (dp[pos][tight][changed] != -1) return dp[pos][tight][changed];
        int limit = tight ? (s[pos] - '0') : 9;
        int res = 0;
        for (int d = 0; d <= limit; d++) {
            bool nextTight = tight && (d == limit);
            // Skip invalid digits
            if (d == 3 || d == 4 || d == 7) continue;
            bool nextChanged = changed || (d == 2 || d == 5 || d == 6 || d == 9);
            res += digitDP(pos + 1, nextTight, nextChanged, s, dp);
        }
        return dp[pos][tight][changed] = res;
    }
    int rotatedDigits_DigitDP(int n) {
        string s = to_string(n);
        int len = s.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(2, vector<int>(2, -1)));
        return digitDP(0, true, false, s, dp);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<int> testCases = {10, 20, 50, 100};
    for (int n : testCases) {
        cout << "n = " << n << "\n";
        cout << "Brute Force: " << sol.rotatedDigits_Brute(n) << "\n";
        cout << "DP Approach: " << sol.rotatedDigits_DP(n) << "\n";
        cout << "Digit DP   : " << sol.rotatedDigits_DigitDP(n) << "\n";
        cout << "--------------------------\n";
    }
    return 0;
}