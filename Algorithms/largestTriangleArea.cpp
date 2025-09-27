#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double area = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    int x3 = points[k][0], y3 = points[k][1];
                    double triangleArea =
                        0.5 *
                        abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    area = max(area, triangleArea);
                }
            }
        }
        return area;
    }
};
int main() {
    Solution sol;
    // Example test case
    vector<vector<int>> points1 = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    double result1 = sol.largestTriangleArea(points1);
    cout << fixed << setprecision(6);
    cout << "Largest Triangle Area (Test Case 1): " << result1 << endl;
    // Additional test cases
    vector<vector<int>> points2 = {{1, 0}, {0, 0}, {0, 1}};
    double result2 = sol.largestTriangleArea(points2);
    cout << "Largest Triangle Area (Test Case 2): " << result2 << endl;
    vector<vector<int>> points3 = {{0, 0}, {1, 1}, {2, 2}, {0, 2}};
    double result3 = sol.largestTriangleArea(points3);
    cout << "Largest Triangle Area (Test Case 3): " << result3 << endl;
    return 0;
}