#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int countPaths(int n, vector<vector<int>>& roads) {
    // Step 1: Build the graph as an adjacency list
    vector<vector<pair<int, int>>> adj(n); // adj[i] = { {neighbor, time}, ... }
    for (const auto& road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }
    // Print the adjacency list for debugging purposes
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Node " << i << " -> ";
        for (const auto& neighbor : adj[i]) {
            cout << "[" << neighbor.first << ", " << neighbor.second << "] ";
        }
        cout << endl;
    }
    // Step 2: Dijkstra's algorithm to find the shortest times and number of ways
    vector<long long> time(n, LLONG_MAX);  // Shortest time to reach each node
    vector<long long> ways(n, 0);          // Number of ways to reach each node
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq; // {time, node}
    // Initial conditions: start at node 0, time = 0, ways = 1
    time[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    cout << "Starting Dijkstra's algorithm..." << endl;
    while (!pq.empty()) {
        int u = pq.top().second;
        long long t = pq.top().first;
        pq.pop();
        // If we already have the shortest time for this node, continue
        if (t > time[u]) continue;
        cout << "Processing node " << u << " with current time " << t << endl;
        // Explore neighbors
        for (const auto& [v, timeEdge] : adj[u]) {
            long long newTime = t + timeEdge;
            cout << "  Exploring edge: " << u << " -> " << v << " with travel time " << timeEdge << endl;
            if (newTime < time[v]) {
                // Found a shorter time to reach v
                time[v] = newTime;
                ways[v] = ways[u];  // Reset the number of ways to the number of ways to reach u
                pq.push({newTime, v});
                cout << "    Found a shorter path to node " << v << " with time " << newTime << ". Ways: " << ways[v] << endl;
            } else if (newTime == time[v]) {
                // Found another shortest path to v, increment ways
                ways[v] = (ways[v] + ways[u]) % MOD;
                cout << "    Found another shortest path to node " << v << " with same time " << newTime << ". Ways: " << ways[v] << endl;
            }
        }
    }
    // Step 3: Return the number of ways to reach node n-1 (the destination)
    cout << "Final number of ways to reach node " << n-1 << " (destination): " << ways[n - 1] << endl;
    return ways[n - 1];
}
int main() {
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };
    cout << "Starting to count paths from 0 to " << n-1 << endl;
    int result = countPaths(n, roads);
    cout << "Number of shortest paths from 0 to " << n-1 << ": " << result << endl;
    return 0;
}