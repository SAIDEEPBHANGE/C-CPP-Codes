#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: DFS (Recursive)
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0') {
            return;
        }
        // Mark as visited
        grid[x][y] = '0';
        // Explore all four directions
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x, y - 1, m, n);
        dfs(grid, x, y + 1, m, n);
    }
public:
    // Approach 1: DFS
    int numIslandsDFS(vector<vector<char>> grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
    // Approach 2: BFS (Queue)
    int numIslandsBFS(vector<vector<char>> grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        int islands = 0;
        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (auto [dx, dy] : directions) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && ny >= 0 &&
                                nx < m && ny < n &&
                                grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    }
    // Approach 3: Disjoint Set Union (DSU)
    int numIslandsDSU(vector<vector<char>> grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        vector<int> parent(m * n);
        vector<int> rank(m * n, 0);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        auto unite = [&](int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return;
            if (rank[pa] < rank[pb]) {
                swap(pa, pb);
            }
            parent[pb] = pa;
            if (rank[pa] == rank[pb]) {
                rank[pa]++;
            }
        };
        int islands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    // Check only right and down to avoid duplicate unions
                    if (i + 1 < m && grid[i + 1][j] == '1') {
                        unite(i * n + j, (i + 1) * n + j);
                    }
                    if (j + 1 < n && grid[i][j + 1] == '1') {
                        unite(i * n + j, i * n + j + 1);
                    }
                }
            }
        }
        // Count distinct land components
        set<int> components;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    components.insert(find(i * n + j));
                }
            }
        }
        return components.size();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<vector<char>>> testCases = {
        {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'}
        },
        {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
        },
        {
            {'1', '0', '1'},
            {'0', '1', '0'},
            {'1', '0', '1'}
        },
        {
            {'0', '0', '0'},
            {'0', '0', '0'},
            {'0', '0', '0'}
        },
        {
            {'1', '1', '1'},
            {'1', '1', '1'},
            {'1', '1', '1'}
        }
    };
    cout << "Number of Islands - Comparison of Approaches\n";
    cout << "=============================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "DFS Result : "
             << sol.numIslandsDFS(testCases[i]) << '\n';
        cout << "BFS Result : "
             << sol.numIslandsBFS(testCases[i]) << '\n';
        cout << "DSU Result : "
             << sol.numIslandsDSU(testCases[i]) << '\n';
        cout << "---------------------------------------------\n";
    }
    return 0;
}