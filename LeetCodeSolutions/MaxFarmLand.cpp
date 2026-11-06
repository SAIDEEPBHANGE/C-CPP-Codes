#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>  // For std::max
using namespace std;
void printvector(const vector<vector<int>>& c) {
    for (const auto& row : c) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
void GetMaxFarm(vector<vector<int>>& c, vector<vector<int>>& d) {
    int m = c.size();  // number of rows
    int n = c[0].size();  // number of columns
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // above
            if (i - 1 >= 0) {
                if (j - 1 >= 0) d[i][j] += c[i - 1][j - 1];  // top-left
                if (j < n) d[i][j] += c[i - 1][j];  // top
                if (j + 1 < n) d[i][j] += c[i - 1][j + 1];  // top-right
            }
            // horizontal
            if (j - 1 >= 0) d[i][j] += c[i][j - 1];  // left
            d[i][j] += c[i][j];  // center
            if (j + 1 < n) d[i][j] += c[i][j + 1];  // right
            // below
            if (i + 1 < m) {
                if (j - 1 >= 0) d[i][j] += c[i + 1][j - 1];  // bottom-left
                if (j < n) d[i][j] += c[i + 1][j];  // bottom
                if (j + 1 < n) d[i][j] += c[i + 1][j + 1];  // bottom-right
            }
            d[i][j] = sqrt(d[i][j]);
        }
    }
}
// Function to return the maximum element in dp matrix
int getMaxInDP(const vector<vector<int>>& dp) {
    int maxVal = dp[0][0];  // Start by assuming the first element is the max
    for (const auto& row : dp) {
        for (int val : row) {
            maxVal = max(maxVal, val);  // Update maxVal if we find a larger value
        }
    }
    return maxVal;
}
int main() {
    vector<vector<int>> input1 = {
        {1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0}
    };
    vector<vector<int>> input2 = {
        {1, 0, 0, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0}
    };
    vector<vector<int>> dp1(5, vector<int>(5, 0));
    vector<vector<int>> dp2(5, vector<int>(5, 0));
    GetMaxFarm(input1, dp1);
    GetMaxFarm(input2, dp2);
    cout << "Input First : " << endl;
    printvector(input1);
    cout << "Input Second : " << endl;
    printvector(input2);
    cout << "Resultant dp1 : " << endl;
    printvector(dp1);
    cout << "Resultant dp2 : " << endl;
    printvector(dp2);
    // Get the maximum value from dp matrices
    cout << "Maximum value in dp1: " << getMaxInDP(dp1) << endl;
    cout << "Maximum value in dp2: " << getMaxInDP(dp2) << endl;
    return 0;
}