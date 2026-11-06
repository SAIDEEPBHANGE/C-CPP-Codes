#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Helper: Check if point (x, y) is inside rectangle from (x1, y1) to (x2, y2)
    bool isInside(int x1, int y1, int x2, int y2, int x, int y) {
        return x1 <= x && x <= x2 && y2 <= y && y <= y1;
    }
    // 1️⃣ Brute-force O(n^3)
    int numberOfPairsBruteForce(vector<vector<int>>& points) {
        int n = points.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 > x2 || y1 < y2) continue;
                bool valid = true;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    int x = points[k][0], y = points[k][1];
                    if (isInside(x1, y1, x2, y2, x, y)) {
                        valid = false;
                        break;
                    }
                }
                if (valid) result++;
            }
        }
        return result;
    }
    // 2️⃣ Optimized O(n^2 log n) with 2D prefix sum
    int numberOfPairsOptimized(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> xs, ys;
        for (auto& p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        unordered_map<int, int> x_map, y_map;
        for (int i = 0; i < xs.size(); ++i) x_map[xs[i]] = i + 1;
        for (int i = 0; i < ys.size(); ++i) y_map[ys[i]] = i + 1;
        int max_x = xs.size() + 2, max_y = ys.size() + 2;
        vector<vector<int>> grid(max_x, vector<int>(max_y, 0));
        for (auto& p : points) {
            int cx = x_map[p[0]];
            int cy = y_map[p[1]];
            grid[cx][cy]++;
        }
        vector<vector<int>> prefix(max_x, vector<int>(max_y, 0));
        for (int i = 1; i < max_x; ++i) {
            for (int j = 1; j < max_y; ++j) {
                prefix[i][j] = grid[i][j]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }
        auto query = [&](int x1, int y1, int x2, int y2) {
            return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
        };
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            int cx1 = x_map[x1], cy1 = y_map[y1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 > x2 || y1 < y2) continue;
                int cx2 = x_map[x2], cy2 = y_map[y2];
                int left = min(cx1, cx2), right = max(cx1, cx2);
                int bottom = min(cy1, cy2), top = max(cy1, cy2);
                int cnt = query(left, bottom, right, top);
                if (cnt == 2) result++;
            }
        }
        return result;
    }
    // 3️⃣ Greedy + Sort O(n^2) practical
    int numberOfPairsGreedySort(vector<vector<int>>& points) {
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };
        sort(points.begin(), points.end(), lambda);
        int n = points.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0], y1 = points[i][1];
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0], y2 = points[j][1];
                if (y1 < y2) continue;
                if (y2 > maxY) {
                    result++;
                    maxY = y2;
                }
            }
        }
        return result;
    }
};
// 🔁 Test runner
int main() {
    Solution sol;
    vector<vector<vector<int>>> testCases = {
        {{1, 3}, {3, 1}, {2, 2}},                 // 1 valid pair
        {{1, 1}, {2, 2}, {3, 3}},                 // 0 valid pairs
        {{1, 4}, {2, 3}, {3, 2}, {4, 1}},         // multiple valid pairs
        {{0, 0}},                                 // 0
        {{0, 0}, {0, 0}},                         // 1
        {{5, 5}, {1, 7}, {3, 3}, {7, 1}},         // edge cases
        {{1, 5}, {2, 4}, {3, 3}, {4, 2}, {5, 1}}, // strictly descending y
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<vector<int>> points = testCases[i];
        int brute = sol.numberOfPairsBruteForce(points);
        int optimized = sol.numberOfPairsOptimized(points);
        int greedy = sol.numberOfPairsGreedySort(points);
        cout << "Test case #" << i + 1 << ":\n";
        cout << "  Points: ";
        for (auto& p : points) cout << "[" << p[0] << "," << p[1] << "] ";
        cout << "\n";
        cout << "  Brute Force: " << brute << "\n";
        cout << "  Optimized:   " << optimized << "\n";
        cout << "  GreedySort:  " << greedy << "\n";
        cout << ((brute == optimized && brute == greedy) ? "  ✅ All Match\n\n" : "  ❌ Mismatch\n\n");
    }
    return 0;
}
