#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void dfsAlgo(int curr, int& n, int& e, vector<vector<int>>& s,
                 vector<bool>& v) {
        n++;
        v[curr] = true;
        for (int& conn : s[curr]) {
            e++;
            if (!v[conn])
                dfsAlgo(conn, n, e, s, v);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& e) {
        vector<vector<int>> s(n);
        for (auto& i : e) {
            s[i[0]].push_back(i[1]);
            s[i[1]].push_back(i[0]);
        }
        int ans = 0;
        vector<bool> v(n, false);
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                int edge = 0;
                int nodes = 0;
                dfsAlgo(i, nodes, edge, s, v);
                if (edge == nodes * (nodes - 1)) // check for a complete graph
                    ans++;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    // Example 1
    int n1 = 6;
    vector<vector<int>> e1 = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    cout << "Number of complete components: " << sol.countCompleteComponents(n1, e1) << endl;
    // Example 2
    int n2 = 5;
    vector<vector<int>> e2 = {{0, 1}, {1, 2}, {3, 4}};
    cout << "Number of complete components: " << sol.countCompleteComponents(n2, e2) << endl;
    return 0;
}