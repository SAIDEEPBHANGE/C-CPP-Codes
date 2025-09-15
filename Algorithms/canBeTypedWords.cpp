#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // First implementation using find and stringstream
    bool canType_v1(string str, string bl) {
        for (auto j : bl) {
            if (str.find(j) != string::npos) {
                return false;
            }
        }
        return true;
    }

public:
    // Version 1: Brute force check using find
    int canBeTypedWords_v1(string text, string brokenLetters) {
        int Result = 0;
        stringstream ss(text);
        string s;
        while (getline(ss, s, ' ')) {
            if (canType_v1(s, brokenLetters)) {
                Result++;
            }
        }
        return Result;
    }

    // Version 2: Optimized using boolean array
    int canBeTypedWords_v2(string text, string brokenLetters) {
        bool broken[26] = {false};
        for (char ch : brokenLetters) {
            broken[ch - 'a'] = true;
        }

        stringstream ss(text);
        string word;
        int result = 0;
        while (ss >> word) {
            bool canType = true;
            for (char ch : word) {
                if (broken[ch - 'a']) {
                    canType = false;
                    break;
                }
            }
            if (canType) {
                result++;
            }
        }
        return result;
    }
};

int main() {
    vector<pair<string, string>> testCases = {
        {"hello world", "ad"},          // Output: 1
        {"leet code", "lt"},            // Output: 1
        {"leet code", ""},              // Output: 2
        {"a b c d e", "e"},             // Output: 4
        {"typing without broken", "x"}, // Output: 3
        {"abc abc abc", "abc"},         // Output: 0
        {"abc abc abc", "z"},           // Output: 3
    };

    Solution sol;
    for (int i = 0; i < testCases.size(); ++i) {
        string text = testCases[i].first;
        string broken = testCases[i].second;

        int res1 = sol.canBeTypedWords_v1(text, broken);
        int res2 = sol.canBeTypedWords_v2(text, broken);

        cout << "Test Case " << i + 1 << ":\n";
        cout << "Text: \"" << text << "\", Broken Letters: \"" << broken << "\"\n";
        cout << "Result v1: " << res1 << ", Result v2: " << res2 << "\n";
        cout << (res1 == res2 ? "✅ Match\n" : "❌ Mismatch\n");
        cout << "----------------------\n";
    }

    return 0;
}
