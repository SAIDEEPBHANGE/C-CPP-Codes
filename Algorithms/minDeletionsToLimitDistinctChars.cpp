#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletionsToLimitDistinctChars(string s, int k) {
        unordered_map<char, int> freq;
        for (char ch : s)
            freq[ch]++;
        int distinct = freq.size();
        if (distinct <= k) return 0;
        vector<int> counts;
        for (auto& [ch, cnt] : freq)
            counts.push_back(cnt);
        sort(counts.begin(), counts.end()); // Delete characters with lowest frequency first
        int deletions = 0;
        int removeCount = distinct - k;
        for (int i = 0; i < removeCount; ++i)
            deletions += counts[i];
        return deletions;
    }
};
int main() {
    vector<pair<string, int>> testCases = {
        {"aaabbbcccddde", 2},    // expected output: 7
        {"abc", 2},              // expected output: 1
        {"aabbcc", 1},           // expected output: 4
        {"aaaaa", 1},            // expected output: 0
        {"abcdabcd", 3},         // expected output: 2
        {"abcabcabc", 5},        // expected output: 0 (already ≤ 5)
        {"zxy", 0},              // expected output: 3 (remove all chars)
        {"", 2}                  // expected output: 0 (empty string)
    };
    Solution sol;
    for (size_t i = 0; i < testCases.size(); ++i) {
        string s = testCases[i].first;
        int k = testCases[i].second;
        int result = sol.minDeletionsToLimitDistinctChars(s, k);
        cout << "Test Case " << i + 1 << ": s = \"" << s << "\", k = " << k << endl;
        cout << "Minimum deletions required: " << result << "\n\n";
    }
    return 0;
}