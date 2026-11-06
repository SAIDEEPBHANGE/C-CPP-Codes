#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        for (auto& dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;
            if (visited[nr][nc])
                continue;
            if (heights[nr][nc] < heights[r][c])
                continue;
            dfs(nr, nc, heights, visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        // DFS from Pacific Ocean (top row and left column)
        for (int i = 0; i < m; ++i) {
            dfs(i, 0, heights, pacific);
            dfs(i, n - 1, heights, atlantic);
        }
        for (int j = 0; j < n; ++j) {
            dfs(0, j, heights, pacific);
            dfs(m - 1, j, heights, atlantic);
        }
        // Collect cells that can flow to both oceans
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
// Utility function to print 2D vector
void printResult(const vector<vector<int>>& result) {
    for (const auto& cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    cout << "\n";
}
int main() {
    Solution sol;
    // Multiple test cases
    vector<vector<vector<int>>> testCases = {
        {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
        },
        {
            {2, 1},
            {1, 2}
        },
        {
            {10, 10, 10},
            {10, 1, 10},
            {10, 10, 10}
        }
    };
    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":\n";
        vector<vector<int>> result = sol.pacificAtlantic(testCases[i]);
        printResult(result);
        cout << "----------------------\n";
    }
    return 0;
}
