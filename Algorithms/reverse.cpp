#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Pure integer math with overflow check (classic)
    int reverseMath(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;

            // Check for overflow before multiplying by 10
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10) {
                return 0;
            }

            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }

    // Approach 2: Use long long to detect overflow after reversal
    int reverseUsingLongLong(int x) {
        long long rev = 0;
        while (x != 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return static_cast<int>(rev);
    }

    // Approach 3: Convert to string and reverse
    int reverseUsingString(int x) {
        bool isNegative = (x < 0);
        string s = to_string(abs(x));

        reverse(s.begin(), s.end());

        long long rev = stoll(s);
        if (isNegative) rev = -rev;

        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return static_cast<int>(rev);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<int> testCases = {
        123,
        -123,
        120,
        0,
        1534236469,   // Overflow case
        -2147483412   // Edge negative case
    };

    cout << "Reverse Integer - Multiple Approaches Comparison\n";
    cout << "------------------------------------------------\n";

    for (int x : testCases) {
        cout << "Input: " << x << "\n";
        cout << "  Approach 1 (Math + Overflow Check): "
             << sol.reverseMath(x) << "\n";
        cout << "  Approach 2 (Using long long):       "
             << sol.reverseUsingLongLong(x) << "\n";
        cout << "  Approach 3 (Using string):          "
             << sol.reverseUsingString(x) << "\n";
        cout << "------------------------------------------------\n";
    }

    return 0;
}
