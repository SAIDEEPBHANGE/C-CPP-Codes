#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string winningPlayer(int x, int y) {
        int moves = min(x, y / 4);
        return (moves % 2) ? "Alice" : "Bob";
    }
};
int main() {
    Solution sol;
    // Vector of test cases: pair<x, y>
    vector<pair<int, int>> testCases = {
        {5, 20},   // Alice wins (5 moves)
        {3, 10},   // Bob wins (2 moves)
        {7, 28},   // Alice wins (7 moves)
        {4, 16},   // Bob wins (4 moves)
        {1, 4},    // Alice wins (1 move)
        {10, 3},   // Bob wins (0 moves - can't make any move)
        {0, 100},  // Bob wins (0 moves - no 75 coin)
        {2, 8},    // Bob wins (2 moves)
        {2, 7},    // Bob wins (1 move only - only 1 valid move)
    };
    for (auto &[x, y] : testCases) {
        cout << "x = " << x << ", y = " << y << " -> "
             << sol.winningPlayer(x, y) << endl;
    }
    return 0;
}