#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int length = 0;
        for (string& word : words) {
            string rev = {word[1], word[0]};
            if (wordCount[rev] > 0) {
                length += 4;
                wordCount[rev]--;
            } else {
                wordCount[word]++;
            }
        }
        // Check for a palindromic center word like "aa", "bb"
        for (auto& [word, count] : wordCount) {
            if (word[0] == word[1] && count > 0) {
                length += 2;
                break; // Only one such center word is allowed
            }
        }
        return length;
    }
};
int main() {
    Solution sol;
    // Define test cases
    vector<vector<string>> testCases = {
        {"lc", "cl", "gg"},
        {"ab", "ty", "yt", "lc", "cl", "ab"},
        {"cc", "ll", "xx"},
        {"ab", "ba", "cd", "dc", "ee"},
        {"aa", "aa", "aa"},
        {"ab", "ba", "aa", "bb", "cc", "dd"}
    };
    // Run each test case
    for (int i = 0; i < testCases.size(); ++i) {
        int result = sol.longestPalindrome(testCases[i]);
        cout << "Test Case " << i + 1 << ": " << result << endl;
    }
    return 0;
}