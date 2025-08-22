#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if (minRow > maxRow || minCol > maxCol) {
            return 0; // No 1's in the grid
        }

        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};

int main() {
    Solution sol;

    // Define test cases
    vector<vector<vector<int>>> testCases = {
        { // Test 1: Normal case
            {0, 0, 0},
            {0, 1, 0},
            {0, 1, 0}
        },
        { // Test 2: All 1s
            {1, 1},
            {1, 1}
        },
        { // Test 3: Single 1
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
        },
        { // Test 4: No 1s
            {0, 0, 0},
            {0, 0, 0}
        },
        { // Test 5: 1s at corners
            {1, 0, 0},
            {0, 0, 0},
            {0, 0, 1}
        }
    };

    // Run and print results
    for (int i = 0; i < testCases.size(); ++i) {
        int area = sol.minimumArea(testCases[i]);
        cout << "Test Case " << i + 1 << ": Minimum Area = " << area << endl;
    }

    return 0;
}
