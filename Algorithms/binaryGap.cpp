#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode: Binary Gap
    Given a positive integer n, return the longest distance between two consecutive 1's
    in the binary representation of n. If there are fewer than two 1's, return 0.
*/

class Solution {
public:

    // ------------------------------------------------------------
    // Approach 1: Using bitset<32>
    // Time Complexity: O(1)  (since 32 bits fixed)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    int binaryGap_bitset(int n) {
        bitset<32> bnum(n);
        int last = -1;
        int result = 0;

        for (int i = 31; i >= 0; i--) {
            if (bnum[i] == 1) {
                if (last != -1) {
                    result = max(result, last - i);
                }
                last = i;
            }
        }
        return result;
    }

    // ------------------------------------------------------------
    // Approach 2: Bit Manipulation (Right Shift)
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    int binaryGap_bitwise(int n) {
        int last = -1;
        int result = 0;
        int index = 0;

        while (n > 0) {
            if (n & 1) {
                if (last != -1) {
                    result = max(result, index - last);
                }
                last = index;
            }
            n >>= 1;
            index++;
        }

        return result;
    }

    // ------------------------------------------------------------
    // Approach 3: Convert to binary string
    // Time Complexity: O(log n)
    // Space Complexity: O(log n)
    // ------------------------------------------------------------
    int binaryGap_string(int n) {
        string binary = "";

        while (n > 0) {
            binary += char((n % 2) + '0');
            n /= 2;
        }

        reverse(binary.begin(), binary.end());

        int last = -1;
        int result = 0;

        for (int i = 0; i < (int)binary.size(); i++) {
            if (binary[i] == '1') {
                if (last != -1) {
                    result = max(result, i - last);
                }
                last = i;
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
    vector<int> testCases = {
        0,
        1,
        5,      // 101 -> gap = 2
        6,      // 110 -> gap = 1
        8,      // 1000 -> gap = 0
        9,      // 1001 -> gap = 3
        22,     // 10110 -> gap = 2
        529,    // 1000010001 -> gap = 4
        1041    // 10000010001 -> gap = 5
    };

    cout << "Binary Gap Comparison\n";
    cout << "---------------------------------------------\n";

    for (int n : testCases) {
        cout << "n = " << n << "\n";
        cout << "  bitset approach  : " << sol.binaryGap_bitset(n) << "\n";
        cout << "  bitwise approach : " << sol.binaryGap_bitwise(n) << "\n";
        cout << "  string approach  : " << sol.binaryGap_string(n) << "\n";
        cout << "---------------------------------------------\n";
    }

    return 0;
}