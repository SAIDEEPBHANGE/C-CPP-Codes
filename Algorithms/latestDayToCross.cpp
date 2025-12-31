#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode: Latest Day to Cross
 We implement multiple approaches inside a single Solution class
 and compare them using a main() with hardcoded test cases.
*/

class Solution {
private:
    /* =========================================================
       Approach 1: DFS simulation day by day
       Time Complexity: O(D * R * C) (can TLE for large inputs)
       ========================================================= */
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis,
             int x, int y, int row, int col) {
        if (x < 0 || x >= row || y < 0 || y >= col)
            return false;
        if (grid[x][y] == 1 || vis[x][y])
            return false;
        if (x == row - 1)
            return true;

        vis[x][y] = true;
        return dfs(grid, vis, x + 1, y, row, col) ||
               dfs(grid, vis, x - 1, y, row, col) ||
               dfs(grid, vis, x, y + 1, row, col) ||
               dfs(grid, vis, x, y - 1, row, col);
    }

public:
    int latestDayToCross_DFS(int row, int col, vector<vector<int>> cells) {
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int lastDay = 0;

        for (auto &cell : cells) {
            int x = cell[0] - 1;
            int y = cell[1] - 1;
            grid[x][y] = 1; // flooded

            bool canCross = false;
            for (int j = 0; j < col && !canCross; j++) {
                if (grid[0][j] == 0) {
                    vector<vector<bool>> vis(row, vector<bool>(col, false));
                    if (dfs(grid, vis, 0, j, row, col))
                        canCross = true;
                }
            }

            if (canCross)
                lastDay++;
            else
                break;
        }
        return lastDay;
    }

    /* =========================================================
       Approach 2: Union-Find (DSU), reverse process
       Time Complexity: O(R * C * α(R*C))
       ========================================================= */
    vector<int> parent, rankv;

    int findSet(int x) {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return;
        if (rankv[a] < rankv[b])
            parent[a] = b;
        else if (rankv[a] > rankv[b])
            parent[b] = a;
        else {
            parent[b] = a;
            rankv[a]++;
        }
    }

    int latestDayToCross_DSU(int row, int col, vector<vector<int>> cells) {
        int n = row * col;
        int TOP = n;
        int BOTTOM = n + 1;

        parent.resize(n + 2);
        rankv.assign(n + 2, 0);
        for (int i = 0; i < n + 2; i++)
            parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 1)); // 1 = water
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int day = (int)cells.size() - 1; day >= 0; day--) {
            int x = cells[day][0] - 1;
            int y = cells[day][1] - 1;
            grid[x][y] = 0; // land
            int id = x * col + y;

            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d];
                int ny = y + dir[d + 1];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                    grid[nx][ny] == 0) {
                    unite(id, nx * col + ny);
                }
            }

            if (x == 0) unite(id, TOP);
            if (x == row - 1) unite(id, BOTTOM);

            if (findSet(TOP) == findSet(BOTTOM))
                return day;
        }
        return 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<tuple<int, int, vector<vector<int>>>> tests = {
        {2, 2, {{1,1},{2,1},{1,2},{2,2}}},
        {2, 2, {{1,1},{1,2},{2,1},{2,2}}},
        {3, 3, {{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}}}
    };

    for (int i = 0; i < (int)tests.size(); i++) {
        int row, col;
        vector<vector<int>> cells;
        tie(row, col, cells) = tests[i];

        cout << "Test Case " << i + 1 << ":\n";
        cout << "  DFS Approach Result : "
             << sol.latestDayToCross_DFS(row, col, cells) << "\n";
        cout << "  DSU Approach Result : "
             << sol.latestDayToCross_DSU(row, col, cells) << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
