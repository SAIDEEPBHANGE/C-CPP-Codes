#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Count Special Positions in a Binary Matrix
    A position (i, j) is special if:
    - mat[i][j] == 1
    - All other elements in row i are 0
    - All other elements in column j are 0
*/
class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Brute Force (Check Row & Column for Every 1)
    // Time Complexity: O(m * n * max(m,n))
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    bool checkCell(int r, int c, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        // Check column
        for (int i = 0; i < m; i++) {
            if (i != r && mat[i][c] == 1)
                return false;
        }
        // Check row
        for (int j = 0; j < n; j++) {
            if (j != c && mat[r][j] == 1)
                return false;
        }
        return true;
    }
    int numSpecialBrute(vector<vector<int>> mat) {
        int m = mat.size();
        int n = mat[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && checkCell(i, j, mat))
                    result++;
            }
        }
        return result;
    }
    // ------------------------------------------------------------
    // Approach 2: Row & Column Counting (Optimal)
    // Time Complexity: O(m * n)
    // Space Complexity: O(m + n)
    // ------------------------------------------------------------
    int numSpecialCounting(vector<vector<int>> mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);
        // First pass: count 1s
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j])
                    rowCount[i]++, colCount[j]++;
        // Second pass: check special
        int result = 0;
        for (int i = 0; i < m; i++)
            if (rowCount[i] == 1)   // pruning
                for (int j = 0; j < n; j++)
                    if (mat[i][j] == 1 && colCount[j] == 1)
                        result++;
        return result;
    }
    // ------------------------------------------------------------
    // Approach 3: Optimized One-Pass with Row Sum Tracking
    // Time Complexity: O(m * n)
    // Space Complexity: O(n)
    // ------------------------------------------------------------
    int numSpecialOptimized(vector<vector<int>> mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> colCount(n, 0);
        int result = 0;
        for (int i = 0; i < m; i++) {
            int rowSum = 0;
            int colIndex = -1;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowSum++;
                    colIndex = j;
                }
            }
            if (rowSum == 1) {
                colCount[colIndex]++;
            }
        }
        // Re-check matrix to validate column uniqueness
        for (int i = 0; i < m; i++) {
            int rowSum = 0;
            int colIndex = -1;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowSum++;
                    colIndex = j;
                }
            }
            if (rowSum == 1 && colCount[colIndex] == 1)
                result++;
        }
        return result;
    }
};
// ------------------------------------------------------------
// Main Function with Hardcoded Test Cases
// ------------------------------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<vector<int>>> testCases = {
        {
            {1,0,0},
            {0,0,1},
            {1,0,0}
        },
        {
            {1,0,0},
            {0,1,0},
            {0,0,1}
        },
        {
            {0,0,0,1},
            {1,0,0,0},
            {0,1,1,0},
            {0,0,0,0}
        }
    };
    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Brute Force Result      : "
             << sol.numSpecialBrute(testCases[t]) << "\n";
        cout << "Row/Column Count Result : "
             << sol.numSpecialCounting(testCases[t]) << "\n";
        cout << "Optimized Result        : "
             << sol.numSpecialOptimized(testCases[t]) << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}