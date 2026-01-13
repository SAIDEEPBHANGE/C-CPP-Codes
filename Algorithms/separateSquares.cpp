#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // -------------------- Approach 1: Direct Binary Search --------------------
    // Uses on-the-fly area computation for each square
    double separateSquares_Basic(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;
        double totalArea = 0.0;

        for (auto &s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        for (int it = 0; it < 100; it++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &s : squares) {
                double y = s[1];
                double l = s[2];

                if (mid <= y) continue;
                if (mid >= y + l)
                    areaBelow += l * l;
                else
                    areaBelow += l * (mid - y);
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }

    // -------------------- Approach 2: Optimized Binary Search --------------------
    // Preprocess squares to reduce repeated computations
    double separateSquares_Optimized(vector<vector<int>>& squares) {
        struct Square {
            double bottom, top, side, area;
        };

        vector<Square> sqs;
        sqs.reserve(squares.size());

        double totalArea = 0.0;
        double low = 1e18, high = -1e18;

        for (auto &s : squares) {
            double y = s[1];
            double l = s[2];
            sqs.push_back({y, y + l, l, l * l});
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double target = totalArea / 2.0;

        for (int it = 0; it < 70; it++) {
            double mid = (low + high) / 2.0;
            double areaBelow = 0.0;

            for (auto &sq : sqs) {
                if (mid <= sq.bottom) continue;
                if (mid >= sq.top)
                    areaBelow += sq.area;
                else
                    areaBelow += sq.side * (mid - sq.bottom);
            }

            if (areaBelow < target)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<vector<int>>> testCases = {
        {{0, 0, 2}},                                   // single square
        {{0, 0, 2}, {0, 2, 2}},                        // stacked squares
        {{1, 1, 2}, {2, 2, 2}},                        // overlapping
        {{0, 0, 4}, {1, 1, 2}, {2, 0, 3}},             // mixed
    };

    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";

        double ans1 = sol.separateSquares_Basic(testCases[i]);
        double ans2 = sol.separateSquares_Optimized(testCases[i]);

        cout << "  Basic Approach      : " << fixed << setprecision(6) << ans1 << "\n";
        cout << "  Optimized Approach  : " << fixed << setprecision(6) << ans2 << "\n";
        cout << "--------------------------------------------------\n";
    }

    return 0;
}
