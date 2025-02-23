#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Naive Approach - Recursion
int lcsRecursion(string X, string Y, int m, int n) {
    // Base case: If any string is empty, return 0
    if (m == 0 || n == 0)
        return 0;
    // If last characters match, include it in the LCS
    if (X[m - 1] == Y[n - 1])
        return 1 + lcsRecursion(X, Y, m - 1, n - 1);
    // Otherwise, check both possibilities and take the maximum
    return max(lcsRecursion(X, Y, m - 1, n), lcsRecursion(X, Y, m, n - 1));
}
// Better Approach - Memoization (Top-Down DP)
int lcsMemoization(string X, string Y, int m, int n, vector<vector<int>>& dp) {
    // Base case: If any string is empty, return 0
    if (m == 0 || n == 0)
        return 0;
    // If the result is already computed, return it
    if (dp[m][n] != -1)
        return dp[m][n];
    // If last characters match, include it in the LCS
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcsMemoization(X, Y, m - 1, n - 1, dp);
    // Otherwise, check both possibilities and take the maximum
    return dp[m][n] = max(lcsMemoization(X, Y, m - 1, n, dp), lcsMemoization(X, Y, m, n - 1, dp));
}
// Expected Approach 1 - Bottom-Up DP (Tabulation)
int lcsTabulation(string X, string Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // Build the dp array in bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
// Expected Approach 2 - Bottom-Up DP with Space Optimization
int lcsSpaceOptimization(string X, string Y, int m, int n) {
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    // Build the dp array in bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr; // Move current row to previous row
    }
    return prev[n];
}
int main() {
    string X = "AGGTAB", Y = "GXTXAYB";
    int m = X.length(), n = Y.length();
    // Naive Approach (Recursion)
    cout << "LCS (Naive) Length: " << lcsRecursion(X, Y, m, n) << endl;
    // Better Approach (Memoization)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << "LCS (Memoization) Length: " << lcsMemoization(X, Y, m, n, dp) << endl;
    // Expected Approach 1 (Bottom-Up DP)
    cout << "LCS (Bottom-Up DP) Length: " << lcsTabulation(X, Y, m, n) << endl;
    // Expected Approach 2 (Space-Optimized DP)
    cout << "LCS (Space-Optimized DP) Length: " << lcsSpaceOptimization(X, Y, m, n) << endl;
    return 0;
}