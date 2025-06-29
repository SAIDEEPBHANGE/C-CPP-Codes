#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    // Recursive DP-based solution
    int solve(const string &s, int k, int i) {
        if (i < 0)
            return 0;
        int take = 0;
        int bit = s[i] - '0';
        long long value = (bit == 1 ? (1LL << (n - i - 1)) : 0);
        if (value <= k) {
            take = 1 + solve(s, k - value, i - 1);
        }
        int skip = solve(s, k, i - 1);
        return max(take, skip);
    }
    int longestSubsequenceRecursive(string s, int k) {
        n = s.length();
        return solve(s, k, n - 1);
    }
    // Greedy bitwise solution
    int longestSubsequenceGreedy(string s, int k) {
        int length = 0;
        long long powerValue = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                length++;
            } else if (powerValue <= k) {
                length++;
                k -= powerValue;
            }
            if (powerValue <= k)
                powerValue <<= 1;
        }
        return length;
    }
};
int main() {
    Solution sol;
    vector<string> testStrings = {
        "1001010",
        "00101001",
        "111",
        "0000",
        "1010101010101010"
    };
    vector<int> testKs = {
        5,
        10,
        1,
        0,
        100
    };
    for (int i = 0; i < testStrings.size(); ++i) {
        string s = testStrings[i];
        int k = testKs[i];
        cout << "Test Case " << i + 1 << ":\n";
        cout << "String: " << s << ", k = " << k << endl;
        cout << "Recursive DP Result: " << sol.longestSubsequenceRecursive(s, k) << endl;
        cout << "Greedy Bitwise Result: " << sol.longestSubsequenceGreedy(s, k) << endl;
        cout << "-----------------------------\n";
    }
    return 0;
}