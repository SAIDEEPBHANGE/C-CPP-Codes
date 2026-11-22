#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Build adjacency list: prerequisite -> dependent course
    vector<vector<int>> buildGraph(
        int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& e : prerequisites) {
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }
    // Approach 1 helper: DFS cycle detection
    bool dfsCycle(int course, vector<bool>& visited,
                  vector<bool>& recursionStack,
                  vector<vector<int>>& adj) {
        visited[course] = true;
        recursionStack[course] = true;
        for (int next : adj[course]) {
            if (!visited[next]) {
                if (dfsCycle(next, visited, recursionStack, adj))
                    return true;
            }
            else if (recursionStack[next]) {
                return true;
            }
        }
        recursionStack[course] = false;
        return false;
    }
    // Approach 1 helper: DFS topological ordering
    void topoOrder(int course, vector<bool>& visited,
                   stack<int>& s, vector<vector<int>>& adj) {
        visited[course] = true;
        for (int next : adj[course]) {
            if (!visited[next]) {
                topoOrder(next, visited, s, adj);
            }
        }
        s.push(course);
    }
    // Approach 2 helper: Three-state DFS
    // 0 = Unvisited, 1 = Visiting, 2 = Visited
    bool dfsColor(int course, vector<int>& state,
                  vector<vector<int>>& adj, vector<int>& order) {
        state[course] = 1;
        for (int next : adj[course]) {
            if (state[next] == 1)
                return false;
            if (state[next] == 0) {
                if (!dfsColor(next, state, adj, order))
                    return false;
            }
        }
        state[course] = 2;
        order.push_back(course);
        return true;
    }
public:
    // Approach 1: Separate cycle detection + DFS topological sort
    // Time: O(V * E), Space: O(V)
    vector<int> findOrderSeparateDFS(
        int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n, false);
        vector<bool> recursionStack(n, false);
        vector<vector<int>> adj = buildGraph(n, prerequisites);
        // Step 1: Detect cycle
        for (int course = 0; course < n; course++) {
            if (!visited[course]) {
                if (dfsCycle(course, visited, recursionStack, adj))
                    return {};
            }
        }
        // Step 2: Generate topological ordering
        visited.assign(n, false);
        stack<int> s;
        for (int course = 0; course < n; course++) {
            if (!visited[course]) {
                topoOrder(course, visited, s, adj);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
    // Approach 2: DFS with three-state coloring
    // Cycle detection and topological ordering together
    // Time: O(V + E), Space: O(V + E)
    vector<int> findOrderDFS(
        int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = buildGraph(n, prerequisites);
        vector<int> state(n, 0);
        vector<int> order;
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                if (!dfsColor(i, state, adj, order))
                    return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
    // Approach 3: BFS - Kahn's Algorithm
    // Time: O(V + E), Space: O(V + E)
    vector<int> findOrderBFS(
        int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = buildGraph(n, prerequisites);
        vector<int> indegree(n, 0);
        for (auto& e : prerequisites) {
            indegree[e[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (int next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }
        if (order.size() != n)
            return {};
        return order;
    }
};
// Utility function to print result
void printOrder(const vector<int>& order) {
    if (order.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < order.size(); i++) {
        cout << order[i];
        if (i != order.size() - 1)
            cout << ", ";
    }
    cout << "]";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<pair<int, vector<vector<int>>>> testCases = {
        {2, {{1, 0}}},
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}},
        {2, {{1, 0}, {0, 1}}},
        {3, {}},
        {3, {{1, 0}, {2, 1}, {0, 2}}},
        {5, {{1, 0}, {2, 0}, {3, 1}, {4, 2}}},
        {1, {}},
        {4, {{1, 0}, {2, 1}, {3, 2}}}
    };
    cout << "Course Schedule II - Approach Comparison\n";
    for (int i = 0; i < testCases.size(); i++) {
        int n = testCases[i].first;
        vector<vector<int>> prerequisites = testCases[i].second;
        cout << "\nTest Case " << i + 1 << ":\n";
        vector<int> result1 =
            sol.findOrderSeparateDFS(n, prerequisites);
        vector<int> result2 =
            sol.findOrderDFS(n, prerequisites);
        vector<int> result3 =
            sol.findOrderBFS(n, prerequisites);
        cout << "1. Separate DFS: ";
        printOrder(result1);
        cout << "\n2. Three-State DFS: ";
        printOrder(result2);
        cout << "\n3. BFS (Kahn's): ";
        printOrder(result3);
        cout << "\n";
    }
    return 0;
}