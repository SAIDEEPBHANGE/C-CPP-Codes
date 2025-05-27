#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original O(n) solution
    int differenceOfSumsOriginal(int n, int m) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (i % m) {
                result += i;
            } else {
                result -= i;
            }
        }
        return result;
    }
    // Optimized O(1) solution using formula
    int differenceOfSumsOptimized(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int k = n / m;
        int divisibleSum = m * k * (k + 1) / 2;
        return totalSum - 2 * divisibleSum;
    }
};
int main() {
    Solution sol;
    // Vector of test cases: {n, m}
    vector<pair<int, int>> testCases = {
        {10, 3},
        {15, 5},
        {1, 1},
        {1000, 7},
        {123456, 123},
        {1000000, 2}
    };
    // Run both versions for each test case
    for (auto& [n, m] : testCases) {
        int originalResult = sol.differenceOfSumsOriginal(n, m);
        int optimizedResult = sol.differenceOfSumsOptimized(n, m);
        cout << "n = " << n << ", m = " << m << "\n";
        cout << "Original Result : " << originalResult << "\n";
        cout << "Optimized Result: " << optimizedResult << "\n";
        cout << (originalResult == optimizedResult ? "✅ Match\n" : "❌ Mismatch\n");
        cout << "-----------------------------\n";
    }
    return 0;
}