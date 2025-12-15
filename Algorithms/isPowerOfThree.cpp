#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Helper function for Recursive Approach
    bool checkPower(long long n, long long pv) {
        if (n == pv)
            return true;
        if (n < pv)
            return false;
        return checkPower(n, pv * 3);
    }
public:
    // Method 1: Division Using Max Power of 3
    bool isPowerOfThree_Division(int n) {
        if (n <= 0) {
            return false;
        }
        // 3^20 = 3486784401 is the highest power of 3 within 32-bit signed int range
        return 3486784401 % n == 0;
    }
    // Method 2: Recursive Multiplication
    bool isPowerOfThree_Recursive(int n) {
        return checkPower(n, 1);
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {1, 3, 9, 27, 45, 0, -3, 243, 3486784401, INT_MAX};
    cout << "Testing both methods:\n\n";
    for (int n : testCases) {
        bool result1 = sol.isPowerOfThree_Division(n);
        bool result2 = sol.isPowerOfThree_Recursive(n);
        cout << "n = " << n << ":\n";
        cout << "  isPowerOfThree_Division: " << (result1 ? "true" : "false") << "\n";
        cout << "  isPowerOfThree_Recursive: " << (result2 ? "true" : "false") << "\n\n";
    }
    return 0;
}
