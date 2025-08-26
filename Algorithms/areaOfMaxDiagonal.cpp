#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDia = -1.0;
        int res = -1;
        for (auto& i : dimensions) {
            int length = i[0];
            int width = i[1];
            double dia = sqrt(length * length + width * width);
            int area = length * width;
            if (dia > maxDia) {
                maxDia = dia;
                res = area;
            } else if (abs(dia - maxDia) < 1e-9) {
                res = max(res, area);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> test1 = {{3, 4}, {6, 8}, {5, 12}};
    cout << "Test Case 1 Output: " << sol.areaOfMaxDiagonal(test1) << endl;
    // Expected: 60

    // Test Case 2: Tie on diagonal, max area wins
    vector<vector<int>> test2 = {{3, 4}, {4, 3}, {5, 0}};
    cout << "Test Case 2 Output: " << sol.areaOfMaxDiagonal(test2) << endl;
    // Expected: 12

    // Test Case 3: Same diagonal, different areas
    vector<vector<int>> test3 = {{6, 8}, {10, 0}, {8, 6}};
    cout << "Test Case 3 Output: " << sol.areaOfMaxDiagonal(test3) << endl;
    // Expected: 48

    // Test Case 4: Single rectangle
    vector<vector<int>> test4 = {{7, 24}};
    cout << "Test Case 4 Output: " << sol.areaOfMaxDiagonal(test4) << endl;
    // Expected: 168

    // Test Case 5: Diagonal tie between multiple, but one has max area
    vector<vector<int>> test5 = {{1, 1}, {2, 2}, {3, 0}, {0, 3}};
    cout << "Test Case 5 Output: " << sol.areaOfMaxDiagonal(test5) << endl;
    // Expected: 4 (2x2 has diag sqrt(8) ~2.828)

    return 0;
}
