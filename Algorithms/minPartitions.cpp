#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Partitioning Into Minimum Number Of Deci-Binary Numbers
    Given a decimal string n, return the minimum number of positive deci-binary numbers needed
    so that they sum up to n.

    Key Insight:
    A deci-binary number contains only digits 0 or 1.
    The minimum number of such numbers required equals the maximum digit in n.
*/

class Solution {
public:

    // ------------------------------------------------------------
    // Approach 1: Linear Scan (Greedy)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    int minPartitions_Linear(string n) {
        int result = 0;
        for (char c : n) {
            result = max(result, c - '0');
        }
        return result;
    }

    // ------------------------------------------------------------
    // Approach 2: Early Exit Optimization
    // Stop immediately if digit '9' is found (maximum possible).
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    int minPartitions_EarlyExit(string n) {
        int result = 0;
        for (char c : n) {
            int digit = c - '0';
            if (digit == 9) return 9;
            result = max(result, digit);
        }
        return result;
    }

    // ------------------------------------------------------------
    // Approach 3: Using STL max_element
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    int minPartitions_STL(string n) {
        char maxDigit = *max_element(n.begin(), n.end());
        return maxDigit - '0';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<string> testCases = {
        "32",
        "82734",
        "27346209830709182346",
        "11111",
        "999999",
        "1000000000"
    };

    cout << "Comparing Different Approaches:\n\n";

    for (const string& test : testCases) {
        cout << "Input: " << test << "\n";

        int ans1 = sol.minPartitions_Linear(test);
        int ans2 = sol.minPartitions_EarlyExit(test);
        int ans3 = sol.minPartitions_STL(test);

        cout << "Linear Scan        : " << ans1 << "\n";
        cout << "Early Exit         : " << ans2 << "\n";
        cout << "STL max_element    : " << ans3 << "\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}