#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized O(n^2) method to count Pythagorean triples
    int countTriples(int n) {
        vector<bool> isSquare(n * n + 1, false);
        for (int i = 1; i <= n; i++) {
            isSquare[i * i] = true;
        }

        int result = 0;

        for (int a = 1; a <= n; a++) {
            int squareA = a * a;
            for (int b = 1; b <= n; b++) {
                int sum = squareA + b * b;
                if (sum <= n * n && isSquare[sum]) {
                    result++;
                }
            }
        }

        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Vector of test cases
    vector<int> testCases = {5, 10, 50, 100};

    for (int n : testCases) {
        cout << "n = " << n << " -> countTriples = "
             << sol.countTriples(n) << "\n";
    }

    return 0;
}
