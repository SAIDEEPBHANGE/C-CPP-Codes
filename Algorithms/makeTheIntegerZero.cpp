#include <iostream>
#include <vector>
#include <bitset>   // Optional if you want to debug binary representation
using namespace std;
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
            long long total_pow2 = (long long)num1 - (long long)k * num2;
            if (total_pow2 < 0)
                continue;
            int bits = __builtin_popcountll(total_pow2);  // Count of 1s in binary
            if (bits <= k)
                return k;
        }
        return -1;
    }
};
int main() {
    Solution sol;
    // Vector of test cases: pair<num1, num2>
    vector<pair<int, int>> testCases = {
        {17, 2},
        {10, 1},
        {5, 10},
        {1000000000, 1},
        {3, 3},
        {9, 2},
        {31, 1},
        {1, 1},
        {64, 0}
    };
    for (auto& testCase : testCases) {
        int num1 = testCase.first;
        int num2 = testCase.second;
        int result = sol.makeTheIntegerZero(num1, num2);
        cout << "makeTheIntegerZero(" << num1 << ", " << num2 << ") = " << result << endl;
    }
    return 0;
}
