#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // -------------------- Approach 1: DFS --------------------
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,
             int x, int y, int px, int py, int m, int n) {
        vis[x][y] = 1;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (auto &d : dirs) {
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if (grid[nx][ny] != grid[x][y])
                continue;
            if (!vis[nx][ny]) {
                if (dfs(grid, vis, nx, ny, x, y, m, n))
                    return true;
            } else if (!(nx == px && ny == py)) {
                return true;
            }
        }
        return false;
    }
    bool containsCycleDFS(vector<vector<char>> grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(grid, vis, i, j, -1, -1, m, n))
                        return true;
                }
            }
        }
        return false;
    }
    // -------------------- Approach 2: BFS --------------------
    bool containsCycleBFS(vector<vector<char>> grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j]) continue;
                queue<tuple<int,int,int,int>> q;
                q.push({i, j, -1, -1});
                vis[i][j] = 1;
                while (!q.empty()) {
                    auto [x, y, px, py] = q.front();
                    q.pop();
                    for (auto &d : dirs) {
                        int nx = x + d[0];
                        int ny = y + d[1];
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                            continue;
                        if (grid[nx][ny] != grid[x][y])
                            continue;
                        if (!vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            q.push({nx, ny, x, y});
                        } else if (!(nx == px && ny == py)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    // -------------------- Approach 3: Union-Find (Basic) --------------------
    bool containsCycleUnionFindBasic(vector<vector<char>> grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n);
        // Initialize parent
        for (int i = 0; i < m * n; i++) parent[i] = i;
        function<int(int)> find = [&](int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };
        auto unite = [&](int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa == pb) return true; // cycle
            parent[pa] = pb;
            return false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                // right
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    if (unite(id, i * n + j + 1))
                        return true;
                }
                // down
                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
                    if (unite(id, (i + 1) * n + j))
                        return true;
                }
            }
        }
        return false;
    }
    // -------------------- Approach 4: Union-Find (Optimized: Rank + Path Compression) --------------------
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]); // path compression
        }
        bool unite(int a, int b) {
            int pa = find(a), pb = find(b);
            if (pa == pb) return true; // cycle detected
            if (rank[pa] < rank[pb]) swap(pa, pb);
            parent[pb] = pa;
            rank[pa] += rank[pb];
            return false;
        }
    };
    bool containsCycleUnionFindOptimized(vector<vector<char>> grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                // right
                if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
                    if (dsu.unite(id, i * n + j + 1))
                        return true;
                }
                // down
                if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
                    if (dsu.unite(id, (i + 1) * n + j))
                        return true;
                }
            }
        }
        return false;
    }
};
// -------------------- MAIN FUNCTION --------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<vector<char>>> testCases = {
        {
            {'a','a','a','a'},
            {'a','b','b','a'},
            {'a','b','b','a'},
            {'a','a','a','a'}
        },
        {
            {'c','c','c','a'},
            {'c','d','c','c'},
            {'c','c','e','c'},
            {'f','c','c','c'}
        },
        {
            {'a','b','b'},
            {'b','z','b'},
            {'b','b','a'}
        },
        {
            {'a'}
        }
    };
    for (int t = 0; t < testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";
        auto grid = testCases[t];
        cout << "DFS: "
             << (sol.containsCycleDFS(grid) ? "Cycle Found" : "No Cycle") << "\n";
        cout << "BFS: "
             << (sol.containsCycleBFS(grid) ? "Cycle Found" : "No Cycle") << "\n";
        cout << "Union-Find (Basic): "
             << (sol.containsCycleUnionFindBasic(grid) ? "Cycle Found" : "No Cycle") << "\n";
        cout << "Union-Find (Optimized): "
             << (sol.containsCycleUnionFindOptimized(grid) ? "Cycle Found" : "No Cycle") << "\n";
        cout << "-------------------------\n";
    }
    return 0;
}