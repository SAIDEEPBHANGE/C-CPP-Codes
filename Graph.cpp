#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
class Graph {
    int V; // Number of vertices
    vector<list<int>> adjList; // Adjacency list
public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }
    // Add an edge to the graph (undirected by default)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph
    }
    // Remove an edge from the graph
    void removeEdge(int u, int v) {
        adjList[u].remove(v);
        adjList[v].remove(u); // For undirected graph
    }
    // Display the graph (Adjacency List)
    void displayGraph() {
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (auto& neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    // Breadth-First Search (BFS)
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS starting from vertex " << start << ": ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            // Visit all the neighbors of the current node
            for (auto& neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    // Depth-First Search (DFS)
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        visited[start] = true;
        s.push(start);
        cout << "DFS starting from vertex " << start << ": ";
        while (!s.empty()) {
            int node = s.top();
            s.pop();
            cout << node << " ";
            // Visit all the neighbors of the current node
            for (auto& neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    // Recursive DFS
    void DFSRecursive(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Recursive starting from vertex " << start << ": ";
        DFSRecursiveHelper(start, visited);
        cout << endl;
    }
    void DFSRecursiveHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto& neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSRecursiveHelper(neighbor, visited);
            }
        }
    }
};
int main() {
    // Create a graph with 6 vertices
    Graph g(6);
    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    // Display the graph
    cout << "Graph (Adjacency List):" << endl;
    g.displayGraph();
    // Perform BFS starting from vertex 0
    g.BFS(0);
    // Perform DFS starting from vertex 0 (Iterative)
    g.DFS(0);
    // Perform DFS starting from vertex 0 (Recursive)
    g.DFSRecursive(0);
    // Remove edge (1, 4)
    cout << "Removing edge (1, 4)" << endl;
    g.removeEdge(1, 4);
    // Display the graph after removing the edge
    cout << "Graph after removing edge (1, 4):" << endl;
    g.displayGraph();
    // Perform BFS starting from vertex 0 after removing the edge
    g.BFS(0);
    return 0;
}