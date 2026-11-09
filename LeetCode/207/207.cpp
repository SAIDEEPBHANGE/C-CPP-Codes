#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // DFS helper: Detect cycle using recursion stack
    bool dfsCycle(int node, vector<bool>& visited,
                  vector<bool>& path, vector<vector<int>>& adj) {
        visited[node] = true;
        path[node] = true;
        for (int next : adj[node]) {
            if (!visited[next]) {
                if (dfsCycle(next, visited, path, adj))
                    return true;
            }
            else if (path[next]) {
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    // DFS helper: Three-state coloring
    // 0 = Unvisited, 1 = Visiting, 2 = Visited
    bool dfsColor(int node, vector<int>& state,
                  vector<vector<int>>& adj) {
        state[node] = 1;
        for (int next : adj[node]) {
            if (state[next] == 1)
                return true;
            if (state[next] == 0) {
                if (dfsColor(next, state, adj))
                    return true;
            }
        }
        state[node] = 2;
        return false;
    }
    vector<vector<int>> buildGraph(
        int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
public:
    // Approach 1: DFS with visited + recursion stack
    // Time: O(V + E), Space: O(V + E)
    bool canFinishDFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = buildGraph(n, edges);
        vector<bool> visited(n, false);
        vector<bool> path(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, visited, path, adj))
                    return false;
            }
        }
        return true;
    }
    // Approach 2: BFS - Kahn's Algorithm
    // Time: O(V + E), Space: O(V + E)
    bool canFinishBFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = buildGraph(n, edges);
        vector<int> indegree(n, 0);
        for (auto& e : edges) {
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int completed = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            completed++;
            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        return completed == n;
    }
    // Approach 3: DFS with three-state coloring
    // Time: O(V + E), Space: O(V + E)
    bool canFinishColorDFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = buildGraph(n, edges);
        vector<int> state(n, 0);
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                if (dfsColor(i, state, adj))
                    return false;
            }
        }
        return true;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<pair<int, vector<vector<int>>>> testCases = {
        {2, {{1, 0}}},
        {2, {{1, 0}, {0, 1}}},
        {4, {{1, 0}, {2, 1}, {3, 2}}},
        {3, {{1, 0}, {2, 1}, {0, 2}}},
        {5, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}},
        {1, {}}
    };
    cout << "Course Schedule - Approach Comparison\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].first;
        vector<vector<int>> edges = testCases[i].second;
        cout << "Test Case " << i + 1 << ":\n";
        cout << "DFS (Recursion Stack): "
             << (sol.canFinishDFS(n, edges) ? "true" : "false")
             << '\n';
        cout << "BFS (Kahn's Algorithm): "
             << (sol.canFinishBFS(n, edges) ? "true" : "false")
             << '\n';
        cout << "DFS (Three-State Coloring): "
             << (sol.canFinishColorDFS(n, edges) ? "true" : "false")
             << "\n\n";
    }
    return 0;
}