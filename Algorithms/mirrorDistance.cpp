#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper: Reverse integer using math
    int reverseMath(int n) {
        int result = 0;
        while (n != 0) {
            result = result * 10 + (n % 10);
            n /= 10;
        }
        return result;
    }

    // Helper: Reverse integer using string
    int reverseString(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }

public:
    // Approach 1: Mathematical reversal (Optimal)
    int mirrorDistanceMath(int n) {
        return abs(n - reverseMath(n));
    }

    // Approach 2: String-based reversal
    int mirrorDistanceString(int n) {
        return abs(n - reverseString(n));
    }

    // Approach 3: Using stack
    int mirrorDistanceStack(int n) {
        int temp = n;
        stack<int> st;

        while (temp > 0) {
            st.push(temp % 10);
            temp /= 10;
        }

        int rev = 0;
        while (!st.empty()) {
            rev = rev * 10 + st.top();
            st.pop();
        }

        return abs(n - rev);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<int> testCases = {123, 100, 1, 909, 1200, 45678};

    cout << "Mirror Distance Results:\n\n";

    for (int n : testCases) {
        cout << "Input: " << n << "\n";
        cout << "Math Approach:    " << sol.mirrorDistanceMath(n) << "\n";
        cout << "String Approach:  " << sol.mirrorDistanceString(n) << "\n";
        cout << "Stack Approach:   " << sol.mirrorDistanceStack(n) << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}