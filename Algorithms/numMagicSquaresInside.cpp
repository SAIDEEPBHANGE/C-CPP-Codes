#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // ---------- Approach 1: Direct Brute Force Validation ----------
    bool checkGridBrute(const vector<vector<int>>& grid, int r, int c) {
        vector<bool> seen(10, false);

        // Check values 1..9 and uniqueness
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        // Check rows
        for (int i = 0; i < 3; i++) {
            int sum = 0;
            for (int j = 0; j < 3; j++)
                sum += grid[r + i][c + j];
            if (sum != 15) return false;
        }

        // Check columns
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int i = 0; i < 3; i++)
                sum += grid[r + i][c + j];
            if (sum != 15) return false;
        }

        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15)
            return false;

        return true;
    }

    // ---------- Approach 2: Optimized Using Magic Square Properties ----------
    bool checkGridOptimized(const vector<vector<int>>& grid, int r, int c) {
        // Center must be 5 in a 3x3 magic square
        if (grid[r + 1][c + 1] != 5) return false;

        vector<int> cnt(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = grid[i][j];
                if (v < 1 || v > 9) return false;
                cnt[v]++;
            }
        }

        for (int v = 1; v <= 9; v++)
            if (cnt[v] != 1) return false;

        // Check all sums
        return
            grid[r][c] + grid[r][c + 1] + grid[r][c + 2] == 15 &&
            grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2] == 15 &&
            grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] == 15 &&
            grid[r][c] + grid[r + 1][c] + grid[r + 2][c] == 15 &&
            grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1] == 15 &&
            grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] == 15 &&
            grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] == 15 &&
            grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] == 15;
    }

public:
    // Approach 1
    int numMagicSquaresBrute(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for (int i = 0; i + 2 < rows; i++)
            for (int j = 0; j + 2 < cols; j++)
                if (checkGridBrute(grid, i, j))
                    ans++;
        return ans;
    }

    // Approach 2
    int numMagicSquaresOptimized(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for (int i = 0; i + 2 < rows; i++)
            for (int j = 0; j + 2 < cols; j++)
                if (checkGridOptimized(grid, i, j))
                    ans++;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<vector<int>>> testCases = {
        {
            {4, 3, 8, 4},
            {9, 5, 1, 9},
            {2, 7, 6, 2}
        },
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 3, 5},
            {1, 6, 11},
            {7, 9, 2}
        }
    };

    for (int t = 0; t < (int)testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Brute Force Result     = "
             << sol.numMagicSquaresBrute(testCases[t]) << "\n";
        cout << "Optimized Result       = "
             << sol.numMagicSquaresOptimized(testCases[t]) << "\n";
        cout << "----------------------------------\n";
    }

    return 0;
}
