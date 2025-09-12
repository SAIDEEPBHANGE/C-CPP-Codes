#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Using for loop
    bool doesAliceWinLoop(const string& s) {
        for (char ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                return true;
            }
        }
        return false;
    }

    // Method 2: Using lambda + STL any_of
    bool doesAliceWinLambda(const string& s) {
        auto isVowel = [](char ch) {
            return string("aeiou").find(ch) != string::npos;
        };
        return any_of(s.begin(), s.end(), isVowel);
    }
};

int main() {
    Solution sol;

    vector<string> testCases = {
        "hello",
        "sky",
        "bcdfg",
        "AI",
        "Umbrella",
        "xyz"
    };

    cout << "Testing doesAliceWinLoop:\n";
    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\" => Output: " << boolalpha << sol.doesAliceWinLoop(s) << "\n";
    }

    cout << "\nTesting doesAliceWinLambda:\n";
    for (const string& s : testCases) {
        cout << "Input: \"" << s << "\" => Output: " << boolalpha << sol.doesAliceWinLambda(s) << "\n";
    }

    return 0;
}
