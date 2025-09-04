#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 🔸 Your original implementation
    int findClosest(int x, int y, int z) {
        int xsteps = abs(z - x);
        int ysteps = abs(z - y);
        if (xsteps >= ysteps) {
            if (xsteps == ysteps) {
                return 0;
            } else {
                return 2;
            }
        }
        return 1;
    }
    // 🔹 Optimal and clean implementation
    int findClosestOptimal(int x, int y, int z) {
        int dx = abs(z - x);
        int dy = abs(z - y);
        if (dx < dy) return 1;
        else if (dy < dx) return 2;
        return 0;
    }
    int findClosestOneLine(int x, int y, int z) {
        int steps = abs(z - x) - abs(z - y);
        return (steps >= 0) ? (steps == 0) ? 0 : 2 : 1;
    }
};
int main() {
    Solution sol;
    vector<tuple<int, int, int>> testCases = {
        {1, 3, 2},     // Both same distance -> 0
        {1, 5, 3},     // Person 1 closer -> 1
        {6, 1, 2},     // Person 2 closer -> 2
        {10, 0, 5},    // Both same -> 0
        {-2, 3, 0},    // Person 1 closer -> 1
    };
    for (auto &[x, y, z] : testCases) {
        cout << "x = " << x << ", y = " << y << ", z = " << z << "\n";
        cout << "  Your Method Result:    " << sol.findClosest(x, y, z) << "\n";
        cout << "  Optimal Method Result: " << sol.findClosestOptimal(x, y, z) << "\n\n";
    }
    return 0;
}