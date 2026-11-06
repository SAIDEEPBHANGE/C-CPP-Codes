#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word) {
        int Result = 1;
        int n = word.size();
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                Result++;
            }
        }
        return Result;
    }
};
int main() {
    Solution sol;
    // Vector of test cases
    vector<string> testCases = {
        "aabbcc",
        "abcde",
        "aaa",
        "aabbaa",
        "ababab",
        "zzzzzz"
    };
    for (auto &test : testCases) {
        cout << "Input: " << test << " -> Output: " << sol.possibleStringCount(test) << "\n";
    }
    return 0;
}