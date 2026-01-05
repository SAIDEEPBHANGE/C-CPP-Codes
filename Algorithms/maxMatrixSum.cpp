#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Greedy using count of negative elements
    // Idea: Sum absolute values. If count of negatives is odd,
    // subtract twice the smallest absolute value.
    long long maxMatrixSumApproach1(vector<vector<int>>& matrix) {
        long long sum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (const auto& row : matrix) {
            for (int val : row) {
                if (val < 0) negCount++;
                minAbs = min(minAbs, abs(val));
                sum += abs(val);
            }
        }

        if (negCount % 2 == 0) return sum;
        return sum - 2LL * minAbs;
    }

    // Approach 2: Track parity of negatives while accumulating
    // Same logic, slightly different implementation style
    long long maxMatrixSumApproach2(vector<vector<int>>& matrix) {
        long long sum = 0;
        bool oddNegatives = false;
        int minAbs = INT_MAX;

        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[i].size(); j++) {
                int x = matrix[i][j];
                if (x < 0) oddNegatives = !oddNegatives;
                sum += llabs(x);
                minAbs = min(minAbs, abs(x));
            }
        }

        return oddNegatives ? sum - 2LL * minAbs : sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<vector<int>>> testCases = {
        {{1, -1}, {-1, 1}},
        {{1, 2, 3}},
        {{-1, -2, -3}},
        {{-1, 0, 2}},
        {{2, -3, -1, 4}}
    };

    for (int t = 0; t < (int)testCases.size(); t++) {
        cout << "Test Case " << t + 1 << ":\n";

        // Copy matrix for each approach (safe practice)
        auto matrix1 = testCases[t];
        auto matrix2 = testCases[t];

        long long ans1 = sol.maxMatrixSumApproach1(matrix1);
        long long ans2 = sol.maxMatrixSumApproach2(matrix2);

        cout << "  Approach 1 Result: " << ans1 << "\n";
        cout << "  Approach 2 Result: " << ans2 << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}
