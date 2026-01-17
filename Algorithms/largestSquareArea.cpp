#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Brute Force (O(n^2))
    // Check every pair of rectangles, compute intersection,
    // and take the largest possible square from that intersection.
    // ------------------------------------------------------------
    long long largestSquareAreaBruteForce(
        vector<vector<int>>& bottomLeft,
        vector<vector<int>>& topRight
    ) {
        int n = bottomLeft.size();
        long long result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left   = max(bottomLeft[i][0], bottomLeft[j][0]);
                int right  = min(topRight[i][0],  topRight[j][0]);
                int bottom = max(bottomLeft[i][1], bottomLeft[j][1]);
                int top    = min(topRight[i][1],  topRight[j][1]);

                if (left < right && bottom < top) {
                    int width  = right - left;
                    int height = top - bottom;
                    int side   = min(width, height);
                    result = max(result, 1LL * side * side);
                }
            }
        }
        return result;
    }

    // ------------------------------------------------------------
    // Approach 2: Optimized Brute Force (Early Pruning)
    // Same O(n^2) complexity, but skips pairs where bounding boxes
    // cannot possibly improve the current best answer.
    // ------------------------------------------------------------
    long long largestSquareAreaOptimized(
        vector<vector<int>>& bottomLeft,
        vector<vector<int>>& topRight
    ) {
        int n = bottomLeft.size();
        long long result = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int maxPossibleWidth =
                    min(topRight[i][0], topRight[j][0]) -
                    max(bottomLeft[i][0], bottomLeft[j][0]);

                int maxPossibleHeight =
                    min(topRight[i][1], topRight[j][1]) -
                    max(bottomLeft[i][1], bottomLeft[j][1]);

                int maxPossibleSide = min(maxPossibleWidth, maxPossibleHeight);

                // Early pruning
                if (maxPossibleSide <= 0 ||
                    1LL * maxPossibleSide * maxPossibleSide <= result)
                    continue;

                int side = maxPossibleSide;
                result = max(result, 1LL * side * side);
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<vector<int>>> testBottomLeft = {
        {{1, 1}, {2, 2}, {3, 1}},
        {{0, 0}, {1, 1}},
        {{0, 0}, {0, 0}, {1, 1}}
    };

    vector<vector<vector<int>>> testTopRight = {
        {{4, 4}, {5, 5}, {6, 3}},
        {{3, 3}, {2, 2}},
        {{2, 2}, {1, 1}, {3, 3}}
    };

    for (int t = 0; t < (int)testBottomLeft.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";

        long long ans1 = sol.largestSquareAreaBruteForce(
            testBottomLeft[t], testTopRight[t]
        );
        long long ans2 = sol.largestSquareAreaOptimized(
            testBottomLeft[t], testTopRight[t]
        );

        cout << "  Brute Force Result     : " << ans1 << "\n";
        cout << "  Optimized Brute Result : " << ans2 << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
