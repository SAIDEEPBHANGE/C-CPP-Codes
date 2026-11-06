#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original map + sort version (cleaned a bit)
    int maxDifference_map(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        int maxOdd = INT_MIN, minEven = INT_MAX;
        bool hasOdd = false, hasEven = false;
        for (auto& [ch, count] : freq) {
            if (count % 2 == 1) {
                hasOdd = true;
                maxOdd = max(maxOdd, count);
            } else {
                hasEven = true;
                minEven = min(minEven, count);
            }
        }
        return (hasOdd && hasEven) ? maxOdd - minEven : 0;
    }
    // Optimized vector version (assumes lowercase a-z only)
    int maxDifference_vector(string s) {
        int odd = -1;
        int even = INT_MAX;
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2) odd = max(odd, freq[i]);
            else even = min(even, freq[i]);
        }
        return (odd != -1 && even != INT_MAX) ? odd - even : 0;
    }
};
int main() {
    Solution sol;
    vector<string> testCases = {
        "aabbcc",       // even counts only, result should be 0
        "aaabbc",       // mix odd and even, result should be 1
        "aaabbbccc",    // all odd, result should be 0
        "aabbccddee",   // all even, result should be 0
        "abcde",        // all odd = 1, no even, result should be 0
        "aaaaabb",      // odd = 5, even = 2, result = 3
        ""              // empty string, result should be 0
    };
    cout << "Testing maxDifference_map:\n";
    for (auto& s : testCases) {
        cout << "Input: " << s << " -> Output: " << sol.maxDifference_map(s) << "\n";
    }
    cout << "\nTesting maxDifference_vector:\n";
    for (auto& s : testCases) {
        cout << "Input: " << s << " -> Output: " << sol.maxDifference_vector(s) << "\n";
    }
    return 0;
}