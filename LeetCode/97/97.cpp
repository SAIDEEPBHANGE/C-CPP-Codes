#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    // Time: O(2^(m+n))
    // Space: O(m+n) - recursion stack
    bool solveRecursive(int i, int j, string &s1, string &s2, string &s3) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }
        int k = i + j;
        bool take1 = false, take2 = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            take1 = solveRecursive(i + 1, j, s1, s2, s3);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            take2 = solveRecursive(i, j + 1, s1, s2, s3);
        }
        return take1 || take2;
    }
    bool isInterleaveRecursive(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        return solveRecursive(0, 0, s1, s2, s3);
    }
    // Approach 2: Recursion + Memoization (Top-Down DP)
    // Time: O(m*n)
    // Space: O(m*n) + O(m+n) recursion stack
    bool solveMemo(int i, int j, string &s1, string &s2,
                   string &s3, vector<vector<int>> &dp) {
        if (i == s1.size() && j == s2.size()) {
            return true;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int k = i + j;
        bool take1 = false, take2 = false;
        if (i < s1.size() && s1[i] == s3[k]) {
            take1 = solveMemo(i + 1, j, s1, s2, s3, dp);
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            take2 = solveMemo(i, j + 1, s1, s2, s3, dp);
        }
        return dp[i][j] = take1 || take2;
    }
    bool isInterleaveMemo(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMemo(0, 0, s1, s2, s3, dp);
    }
    // Approach 3: Tabulation (Bottom-Up DP)
    // Time: O(m*n)
    // Space: O(m*n)
    bool isInterleaveTabulation(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(
            m + 1, vector<bool>(n + 1, false)
        );
        dp[0][0] = true;
        // Initialize first column.
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] &&
                       (s1[i - 1] == s3[i - 1]);
        }
        // Initialize first row.
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] &&
                       (s2[j - 1] == s3[j - 1]);
        }
        // Fill the DP table.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                bool take1 = dp[i - 1][j] &&
                             (s1[i - 1] == s3[k]);
                bool take2 = dp[i][j - 1] &&
                             (s2[j - 1] == s3[k]);
                dp[i][j] = take1 || take2;
            }
        }
        return dp[m][n];
    }
    // Approach 4: Space Optimized DP
    // Time: O(m*n)
    // Space: O(n)
    bool isInterleaveSpaceOptimized(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) {
            return false;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // Initialize first row.
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] &&
                    (s2[j - 1] == s3[j - 1]);
        }
        for (int i = 1; i <= m; i++) {
            // Update first column.
            dp[0] = dp[0] &&
                    (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;
                bool take1 = dp[j] &&
                             (s1[i - 1] == s3[k]);
                bool take2 = dp[j - 1] &&
                             (s2[j - 1] == s3[k]);
                dp[j] = take1 || take2;
            }
        }
        return dp[n];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases.
    vector<tuple<string, string, string>> testCases = {
        {"aabcc", "dbbca", "aadbbcbcac"},
        {"aabcc", "dbbca", "aadbbbaccc"},
        {"", "", ""},
        {"", "abc", "abc"},
        {"abc", "", "abc"},
        {"a", "b", "ab"},
        {"a", "b", "ba"},
        {"aa", "ab", "aaba"},
        {"abc", "def", "adbcef"}
    };
    cout << "Interleaving String - Approach Comparison\n";
    cout << "==========================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        auto [s1, s2, s3] = testCases[i];
        cout << "Test Case " << i + 1 << ":\n";
        cout << "s1 = \"" << s1 << "\"\n";
        cout << "s2 = \"" << s2 << "\"\n";
        cout << "s3 = \"" << s3 << "\"\n\n";
        // Avoid exponential recursion on large inputs.
        if (s1.size() + s2.size() <= 25) {
            cout << "1. Recursion:          "
                 << (sol.isInterleaveRecursive(s1, s2, s3)
                     ? "True" : "False") << '\n';
        } else {
            cout << "1. Recursion:          Skipped\n";
        }
        cout << "2. Memoization:        "
             << (sol.isInterleaveMemo(s1, s2, s3)
                 ? "True" : "False") << '\n';
        cout << "3. Tabulation:         "
             << (sol.isInterleaveTabulation(s1, s2, s3)
                 ? "True" : "False") << '\n';
        cout << "4. Space Optimized:    "
             << (sol.isInterleaveSpaceOptimized(s1, s2, s3)
                 ? "True" : "False") << '\n';
        cout << "------------------------------------------\n";
    }
    return 0;
}