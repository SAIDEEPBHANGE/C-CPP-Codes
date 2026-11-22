#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: Recursive DFS
    int dfs(string& t1, string& t2, int i, int j) {
        if (i == t1.size() || j == t2.size())
            return 0;
        if (t1[i] == t2[j]) {
            return 1 + dfs(t1, t2, i + 1, j + 1);
        }
        return max(
            dfs(t1, t2, i + 1, j),
            dfs(t1, t2, i, j + 1)
        );
    }
    // Approach 2: DFS + Memoization
    int memoDFS(string& t1, string& t2, int i, int j,
                vector<vector<int>>& dp) {
        if (i == t1.size() || j == t2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (t1[i] == t2[j]) {
            return dp[i][j] =
                1 + memoDFS(t1, t2, i + 1, j + 1, dp);
        }
        return dp[i][j] = max(
            memoDFS(t1, t2, i + 1, j, dp),
            memoDFS(t1, t2, i, j + 1, dp)
        );
    }
public:
    // Approach 1: Recursion
    int longestCommonSubsequenceRecursive(string t1, string t2) {
        return dfs(t1, t2, 0, 0);
    }
    // Approach 2: Recursion + Memoization
    int longestCommonSubsequenceMemo(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoDFS(t1, t2, 0, 0, dp);
    }
    // Approach 3: DP - Tabulation
    int longestCommonSubsequenceDP(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }
        return dp[m][n];
    }
    // Approach 4: DP - Space Optimization
    int longestCommonSubsequenceOptimized(string t1, string t2) {
        int m = t1.size();
        int n = t2.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t1[i - 1] == t2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
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
        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"},
        {"AGGTAB", "GXTXAYB"},
        {"bl", "yby"}
    };
    cout << "Longest Common Subsequence - Approach Comparison\n";
    cout << "=================================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        string t1 = testCases[i].first;
        string t2 = testCases[i].second;
        int recursiveResult =
            sol.longestCommonSubsequenceRecursive(t1, t2);
        int memoResult =
            sol.longestCommonSubsequenceMemo(t1, t2);
        int dpResult =
            sol.longestCommonSubsequenceDP(t1, t2);
        int optimizedResult =
            sol.longestCommonSubsequenceOptimized(t1, t2);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "String 1: " << t1 << "\n";
        cout << "String 2: " << t2 << "\n";
        cout << "Recursion: " << recursiveResult << "\n";
        cout << "Memoization: " << memoResult << "\n";
        cout << "DP (Tabulation): " << dpResult << "\n";
        cout << "DP (Space Optimized): " << optimizedResult << "\n";
        cout << "-------------------------------------------------\n";
    }
    return 0;
}
