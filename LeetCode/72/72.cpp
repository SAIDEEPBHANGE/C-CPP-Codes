#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Recursion (Brute Force)
    int solveRec(int i, int j, string &s1, string &s2) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (s1[i - 1] == s2[j - 1]) {
            return solveRec(i - 1, j - 1, s1, s2);
        }
        int insert = solveRec(i, j - 1, s1, s2);
        int del = solveRec(i - 1, j, s1, s2);
        int replace = solveRec(i - 1, j - 1, s1, s2);
        return 1 + min({insert, del, replace});
    }
    int minDistanceRecursive(string word1, string word2) {
        return solveRec(word1.size(), word2.size(), word1, word2);
    }
    // Approach 2: Recursion + Memoization
    int solveMemo(int i, int j, string &s1, string &s2,
                  vector<vector<int>> &dp) {
        if (i == 0) return j;
        if (j == 0) return i;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] =
                solveMemo(i - 1, j - 1, s1, s2, dp);
        }
        int insert = solveMemo(i, j - 1, s1, s2, dp);
        int del = solveMemo(i - 1, j, s1, s2, dp);
        int replace = solveMemo(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = 1 + min({insert, del, replace});
    }
    int minDistanceMemo(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solveMemo(m, n, word1, word2, dp);
    }
    // Approach 3: Tabulation (Bottom-Up DP)
    int minDistanceTabulation(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // Base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        // DP transitions
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insert = dp[i][j - 1];
                    int del = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min({insert, del, replace});
                }
            }
        }
        return dp[m][n];
    }
    // Approach 4: Space Optimized DP
    int minDistanceOptimized(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        // Base case
        for (int j = 0; j <= n; j++) {
            prev[j] = j;
        }
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    int insert = curr[j - 1];
                    int del = prev[j];
                    int replace = prev[j - 1];
                    curr[j] = 1 + min({insert, del, replace});
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<pair<string, string>> testCases = {
        {"horse", "ros"},
        {"intention", "execution"},
        {"", "abc"},
        {"abc", ""},
        {"abc", "abc"},
        {"kitten", "sitting"}
    };
    cout << "EDIT DISTANCE - APPROACH COMPARISON\n";
    cout << "===================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        string word1 = testCases[i].first;
        string word2 = testCases[i].second;
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Word1: \"" << word1 << "\"\n";
        cout << "Word2: \"" << word2 << "\"\n";
        cout << "Recursion:          "
             << sol.minDistanceRecursive(word1, word2) << '\n';
        cout << "Memoization:        "
             << sol.minDistanceMemo(word1, word2) << '\n';
        cout << "Tabulation:         "
             << sol.minDistanceTabulation(word1, word2) << '\n';
        cout << "Space Optimized DP: "
             << sol.minDistanceOptimized(word1, word2) << '\n';
        cout << "-----------------------------------\n";
    }
    return 0;
}
