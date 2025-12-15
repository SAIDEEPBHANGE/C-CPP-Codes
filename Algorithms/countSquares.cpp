#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<vector<int>>> testCases = {
        {{0,1,1,1},{1,1,1,1},{0,1,1,1}},
        {{1,0,1},{1,1,0},{1,1,0}},
        {{1,1},{1,1}},
        {{0,0},{0,0}},
        {{1}},
        {{0}}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i+1 << ": ";
        int result = sol.countSquares(testCases[i]);
        cout << "Total square submatrices with all ones = " << result << endl;
    }
    return 0;
}
