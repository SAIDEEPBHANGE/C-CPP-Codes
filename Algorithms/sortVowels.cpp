#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Naive approach (uses find and two strings)
    string sortVowelsNaive(string s) {
        vector<char> vowelList = {'a', 'e', 'i', 'o', 'u'};
        string vowels;
        string consonants;
        for (char c : s) {
            if (find(vowelList.begin(), vowelList.end(), tolower(c)) != vowelList.end()) {
                vowels += c;
            } else {
                consonants += c;
            }
        }
        sort(vowels.begin(), vowels.end());
        string result;
        int vowelIndex = 0;
        int consonantIndex = 0;
        for (char c : s) {
            if (find(vowelList.begin(), vowelList.end(), tolower(c)) != vowelList.end()) {
                result += vowels[vowelIndex++];
            } else {
                result += consonants[consonantIndex++];
            }
        }
        return result;
    }
    // Optimized approach (uses unordered_set and modifies in place)
    string sortVowelsOptimized(string s) {
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u',
                                         'A', 'E', 'I', 'O', 'U'};
        vector<char> vowels;
        // Step 1: Extract vowels
        for (char c : s) {
            if (vowelsSet.count(c)) {
                vowels.push_back(c);
            }
        }
        // Step 2: Sort vowels
        sort(vowels.begin(), vowels.end());
        // Step 3: Replace vowels in original string
        int idx = 0;
        for (char &c : s) {
            if (vowelsSet.count(c)) {
                c = vowels[idx++];
            }
        }
        return s;
    }
};
int main() {
    Solution sol;
    // Vector of test cases
    vector<string> testCases = {
        "lEetcOde",   // Mixed case
        "hello",      // Simple
        "AEIOU",      // All vowels uppercase
        "bcdfg",      // No vowels
        "",           // Empty string
        "aAeiIoOuU"   // All vowels mixed
    };
    cout << "==== Testing sortVowelsNaive ====" << endl;
    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\" => Output: \"" << sol.sortVowelsNaive(test) << "\"" << endl;
    }
    cout << "\n==== Testing sortVowelsOptimized ====" << endl;
    for (const string& test : testCases) {
        cout << "Input: \"" << test << "\" => Output: \"" << sol.sortVowelsOptimized(test) << "\"" << endl;
    }
    return 0;
}
