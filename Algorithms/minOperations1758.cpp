#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
        Approach 1: Compare with both possible alternating patterns
        Pattern A: 010101...
        Pattern B: 101010...
        Count mismatches with both and return the minimum.
        Time: O(n)
        Space: O(1)
    */
    int approachPatternCompare(string s) {
        int n = s.size();
        int mismatchStart0 = 0; // pattern starting with '0'
        int mismatchStart1 = 0; // pattern starting with '1'
        for (int i = 0; i < n; i++) {
            char expected0 = (i % 2) + '0';
            char expected1 = ((i + 1) % 2) + '0';
            if (s[i] != expected0) mismatchStart0++;
            if (s[i] != expected1) mismatchStart1++;
        }
        return min(mismatchStart0, mismatchStart1);
    }
    /*
        Approach 2: Greedy counting
        Count mismatches assuming the string should start with '0'.
        If mismatches = x, then flips needed for pattern 0101... = x
        For pattern 1010... = n - x
        Return min(x, n - x)
        Time: O(n)
        Space: O(1)
    */
    int approachGreedy(string s) {
        int n = s.size();
        int mismatch = 0;
        for (int i = 0; i < n; i++) {
            char expected = (i % 2) + '0';
            if (s[i] != expected) mismatch++;
        }
        return min(mismatch, n - mismatch);
    }
    /*
        Approach 3: Explicit pattern construction
        Build both alternating strings and compute Hamming distance.
        Time: O(n)
        Space: O(n)
    */
    int approachBuildPattern(string s) {
        int n = s.size();
        string p1 = "", p2 = "";
        for (int i = 0; i < n; i++) {
            p1 += (i % 2) + '0';
            p2 += ((i + 1) % 2) + '0';
        }
        int diff1 = 0, diff2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != p1[i]) diff1++;
            if (s[i] != p2[i]) diff2++;
        }
        return min(diff1, diff2);
    }
    /*
        Original LeetCode style function
    */
    int minOperations(string s) {
        return approachPatternCompare(s);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<string> testCases = {
        "0100",
        "10",
        "1111",
        "0000",
        "101010",
        "100101",
        "0110"
    };
    cout << "Testing Minimum Operations to Make Alternating Binary String\n\n";
    for (auto &s : testCases) {
        cout << "Input: " << s << "\n";
        int res1 = sol.approachPatternCompare(s);
        int res2 = sol.approachGreedy(s);
        int res3 = sol.approachBuildPattern(s);
        cout << "Approach 1 (Pattern Compare): " << res1 << "\n";
        cout << "Approach 2 (Greedy Count):   " << res2 << "\n";
        cout << "Approach 3 (Build Pattern):  " << res3 << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}