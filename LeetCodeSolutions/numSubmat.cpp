#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp = mat;
        // Preprocess to calculate consecutive 1s in each row
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (dp[i][j])
                    dp[i][j] += dp[i][j - 1];
            }
        }
        int res = 0;
        // Count submatrices ending at each (i,j)
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                int minWidth = dp[i][j];
                for (int k = i; k >= 0 && minWidth > 0; --k) {
                    minWidth = min(minWidth, dp[k][j]);
                    res += minWidth;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    // Define test cases
    vector<vector<vector<int>>> testCases = {
        {
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 0}
        },
        {
            {0, 1, 1, 0},
            {0, 1, 1, 1},
            {1, 1, 1, 0}
        },
        {
            {1, 1},
            {1, 1}
        },
        {
            {0, 0},
            {0, 0}
        },
        {
            {1}
        },
        {
            {0}
        }
    };
    // Run test cases
    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << " result: " << sol.numSubmat(testCases[i]) << endl;
    }
    return 0;
}
