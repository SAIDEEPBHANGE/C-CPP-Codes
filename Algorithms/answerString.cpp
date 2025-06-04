#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int longestPossible = n - (numFriends - 1);
        string result;
        if (longestPossible == n) {
            return word;
        }
        for (int i = 0; i < n; i++) {
            int canPossible = min(longestPossible, n - i);
            result = max(result, word.substr(i, canPossible));
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<pair<string, int>> testCases = {
        {"abc", 2},          // Expected: "c"
        {"helloworld", 3},   // Expected: "world"
        {"abcdxyz", 4},      // Expected: "xyz"
        {"aaaaa", 2},        // Expected: "aaaa"
        {"zxyab", 2},        // Expected: "zxy"
        {"baaaac", 3},       // Expected: "aaa"
        {"abcde", 5},        // Expected: "e"
        {"abacabadabacaba", 4} // Expected: "dabacaba"
    };
    for (auto& [word, numFriends] : testCases) {
        string result = sol.answerString(word, numFriends);
        cout << "Input: \"" << word << "\", Friends: " << numFriends
             << " => Output: \"" << result << "\"\n";
    }
    return 0;
}