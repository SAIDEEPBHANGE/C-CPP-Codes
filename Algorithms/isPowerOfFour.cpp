#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive helper for method 2
    bool checkPowerOfFourRecursive(long long n, long long k) {
        if (n == k)
            return true;
        if (n < k)
            return false;
        return checkPowerOfFourRecursive(n, k * 4);
    }

public:
    // Method 1: Bit Manipulation
    bool isPowerOfFourBitwise(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xAAAAAAAA) == 0;
    }

    // Method 2: Recursive Approach
    bool isPowerOfFourRecursive(int n) {
        return checkPowerOfFourRecursive(n, 1);
    }
};

int main() {
    Solution sol;

    vector<int> testCases = {
        1,     // true
        4,     // true
        16,    // true
        64,    // true
        5,     // false
        8,     // false
        0,     // false
        -4,    // false
        1024,  // false
        256    // true
    };

    cout << "Test Results:\n";
    for (int n : testCases) {
        cout << "n = " << n
             << " | Bitwise: " << boolalpha << sol.isPowerOfFourBitwise(n)
             << " | Recursive: " << sol.isPowerOfFourRecursive(n) << '\n';
    }

    return 0;
}
