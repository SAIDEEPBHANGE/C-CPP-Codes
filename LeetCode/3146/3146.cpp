#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 🔹 Approach 1: Using unordered_map with vector (your method)
    int findPermutationDifference_mapVector(string s, string t) {
        unordered_map<int, vector<int>> ump;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            ump[s[i]].push_back(i);
            ump[t[i]].push_back(i);
        }
        int Result = 0;
        for (auto &i : ump) {
            vector<int> arr = i.second;
            Result += abs(arr[0] - arr[1]);
        }
        return Result;
    }
    // 🔹 Approach 2: Using string::find (your second method)
    int findPermutationDifference_find(string s, string t) {
        int n = s.size();
        int Result = 0;
        for (int i = 0; i < n; i++) {
            Result += abs(i - (int)t.find(s[i]));
        }
        return Result;
    }
    // 🔹 Approach 3: Optimal map-based (my approach)
    int findPermutationDifference_optimal(string s, string t) {
        unordered_map<char, int> posS, posT;
        for (int i = 0; i < s.size(); ++i) {
            posS[s[i]] = i;
            posT[t[i]] = i;
        }
        int total = 0;
        for (auto &[ch, indexS] : posS) {
            total += abs(indexS - posT[ch]);
        }
        return total;
    }
};
int main() {
    Solution sol;
    vector<pair<string, string>> testCases = {
        {"abc", "bca"},       // Expected: 4
        {"abcd", "dcba"},     // Expected: 8
        {"xyz", "xyz"},       // Expected: 0
        {"abcde", "edcba"},   // Expected: 12
        {"a", "a"},           // Expected: 0
    };
    for (auto &[s, t] : testCases) {
        cout << "s = " << s << ", t = " << t << "\n";
        cout << "  Map + Vector Approach:     " << sol.findPermutationDifference_mapVector(s, t) << "\n";
        cout << "  Find Function Approach:    " << sol.findPermutationDifference_find(s, t) << "\n";
        cout << "  Optimal Map Approach:      " << sol.findPermutationDifference_optimal(s, t) << "\n\n";
    }
    return 0;
}