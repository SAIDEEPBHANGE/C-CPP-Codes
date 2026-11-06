#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(const vector<string>& words, char x) {
        vector<int> result;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) != string::npos) {
                result.push_back(i);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Test cases
    vector<vector<string>> testCases = {
        {"apple", "banana", "cherry", "date"},
        {"hello", "world", "chatgpt", "openai"},
        {"abc", "def", "ghi", "jkl"},
        {"xray", "xerox", "max", "box"}
    };
    vector<char> testChars = {'a', 'o', 'z', 'x'};
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> result = sol.findWordsContaining(testCases[i], testChars[i]);
        cout << "Test Case " << i + 1 << " (char = '" << testChars[i] << "'):\n";
        cout << "Matching word indices: ";
        for (int idx : result) {
            cout << idx << " ";
        }
        cout << "\n\n";
    }
    return 0;
}