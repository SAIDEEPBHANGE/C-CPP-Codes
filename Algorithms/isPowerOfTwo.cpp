#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Method 1: Iterative method using powers of 2
    bool isPowerOfTwo_iterative(int n) {
        if (n == 1)
            return true;
        long long ans = 1;
        for (int i = 1; i <= 31; i++) {
            ans = ans * 2;
            if (ans == n) {
                return true;
            }
        }
        return false;
    }
    // Method 2: Recursive method
    bool recursiveHelper(int n, long long ans) {
        if (n == ans)
            return true;
        if (n < ans)
            return false;
        return recursiveHelper(n, ans * 2);
    }
    bool isPowerOfTwo_recursive(int n) {
        if (n <= 0) return false;
        return recursiveHelper(n, 1);
    }
    // Method 3: Bit manipulation method
    bool isPowerOfTwo_bitwise(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {1, 2, 3, 4, 8, 16, 31, 64, 127, 128, 1024, 2047, 2048, 0, -2};
    cout << "Testing all methods for power of two:\n";
    for (int n : testCases) {
        cout << "\nNumber: " << n << "\n";
        cout << "Iterative: " << (sol.isPowerOfTwo_iterative(n) ? "True" : "False") << "\n";
        cout << "Recursive: " << (sol.isPowerOfTwo_recursive(n) ? "True" : "False") << "\n";
        cout << "Bitwise:   " << (sol.isPowerOfTwo_bitwise(n) ? "True" : "False") << "\n";
    }
    return 0;
}
