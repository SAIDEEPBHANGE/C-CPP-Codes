#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Recursion (Brute Force)
    bool solveRecursive(int i, int j, string& s, string& p) {
        int n = s.size();
        int m = p.size();
        if (j == m)
            return i == n;
        bool firstMatch = (i < n &&
                          (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < m && p[j + 1] == '*') {
            bool zero = solveRecursive(i, j + 2, s, p);
            bool more = firstMatch &&
                        solveRecursive(i + 1, j, s, p);
            return zero || more;
        }
        return firstMatch &&
               solveRecursive(i + 1, j + 1, s, p);
    }
public:
    // Approach 1: Recursion
    bool isMatchRecursive(string s, string p) {
        return solveRecursive(0, 0, s, p);
    }
private:
    // Approach 2: Memoization
    bool solveMemo(int i, int j, string& s, string& p,
                   vector<vector<int>>& dp) {
        int n = s.size();
        int m = p.size();
        if (j == m)
            return i == n;
        if (dp[i][j] != -1)
            return dp[i][j];
        bool firstMatch = (i < n &&
                          (s[i] == p[j] || p[j] == '.'));
        bool ans = false;
        if (j + 1 < m && p[j + 1] == '*') {
            // Zero occurrences
            bool zero = solveMemo(i, j + 2, s, p, dp);
            // One or more occurrences
            bool more = firstMatch &&
                        solveMemo(i + 1, j, s, p, dp);
            ans = zero || more;
        }
        else {
            ans = firstMatch &&
                  solveMemo(i + 1, j + 1, s, p, dp);
        }
        return dp[i][j] = ans;
    }
public:
    // Approach 2: Memoization
    bool isMatchMemo(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );
        return solveMemo(0, 0, s, p, dp);
    }
    // Approach 3: Tabulation (Bottom-Up DP)
    bool isMatchTabulation(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(
            n + 1, vector<bool>(m + 1, false)
        );
        // Both strings empty
        dp[n][m] = true;
        // Empty string matching pattern with *
        for (int j = m - 1; j >= 0; j--) {
            if (j + 1 < m && p[j + 1] == '*') {
                dp[n][j] = dp[n][j + 2];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool firstMatch =
                    (s[i] == p[j] || p[j] == '.');
                if (j + 1 < m && p[j + 1] == '*') {
                    // Zero occurrences
                    bool zero = dp[i][j + 2];
                    // One or more occurrences
                    bool more = firstMatch && dp[i + 1][j];
                    dp[i][j] = zero || more;
                }
                else {
                    dp[i][j] =
                        firstMatch && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
    // Approach 4: Space Optimized DP
    bool isMatchSpaceOptimized(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> next(m + 1, false);
        vector<bool> curr(m + 1, false);
        // Base case: both strings exhausted
        next[m] = true;
        // Empty string matching pattern with *
        for (int j = m - 1; j >= 0; j--) {
            if (j + 1 < m && p[j + 1] == '*') {
                next[j] = next[j + 2];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            fill(curr.begin(), curr.end(), false);
            for (int j = m - 1; j >= 0; j--) {
                bool firstMatch =
                    (s[i] == p[j] || p[j] == '.');
                if (j + 1 < m && p[j + 1] == '*') {
                    bool zero = curr[j + 2];
                    bool more = firstMatch && next[j];
                    curr[j] = zero || more;
                }
                else {
                    curr[j] =
                        firstMatch && next[j + 1];
                }
            }
            next = curr;
        }
        return next[0];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<pair<string, string>> testCases = {
        {"aa", "a"},
        {"aa", "a*"},
        {"ab", ".*"},
        {"aab", "c*a*b"},
        {"mississippi", "mis*is*p*."},
        {"aaa", "a*a"},
        {"", "a*b*"},
        {"", ""},
        {"abc", "abc"},
        {"abcd", "d*"}
    };
    cout << "REGULAR EXPRESSION MATCHING (LC 10)\n";
    cout << "====================================\n\n";
    cout << left
         << setw(18) << "Input String"
         << setw(22) << "Pattern"
         << setw(15) << "Recursion"
         << setw(15) << "Memoization"
         << setw(15) << "Tabulation"
         << setw(15) << "Optimized"
         << '\n';
    cout << string(100, '-') << '\n';
    for (auto& test : testCases) {
        string s = test.first;
        string p = test.second;
        bool ans1 = sol.isMatchRecursive(s, p);
        bool ans2 = sol.isMatchMemo(s, p);
        bool ans3 = sol.isMatchTabulation(s, p);
        bool ans4 = sol.isMatchSpaceOptimized(s, p);
        cout << left
             << setw(18) << (s.empty() ? "\"\"" : s)
             << setw(22) << (p.empty() ? "\"\"" : p)
             << setw(15) << (ans1 ? "true" : "false")
             << setw(15) << (ans2 ? "true" : "false")
             << setw(15) << (ans3 ? "true" : "false")
             << setw(15) << (ans4 ? "true" : "false")
             << '\n';
    }
    return 0;
}
