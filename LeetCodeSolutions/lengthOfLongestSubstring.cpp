#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Optimal Sliding Window using last occurrence array
    // Time: O(n), Space: O(1)
    int lengthOfLongestSubstring_SlidingWindowArray(const string &s) {
        vector<int> last(256, -1);
        int left = 0, result = 0;
        for (int right = 0; right < (int)s.size(); right++) {
            if (last[s[right]] >= left) {
                left = last[s[right]] + 1;
            }
            last[s[right]] = right;
            result = max(result, right - left + 1);
        }
        return result;
    }
    // Approach 2: Sliding Window using string operations
    // Time: O(n^2) in worst case, Space: O(n)
    int lengthOfLongestSubstring_SlidingWindowString(const string &s) {
        int result = 0;
        string window = "";
        for (char c : s) {
            int pos = window.find(c);
            if (pos == string::npos) {
                window += c;
            } else {
                result = max(result, (int)window.size());
                window = window.substr(pos + 1);
                window += c;
            }
        }
        result = max(result, (int)window.size());
        return result;
    }
    // Approach 3: Brute Force with Set
    // Time: O(n^2), Space: O(n)
    int lengthOfLongestSubstring_BruteForce(const string &s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for (int j = i; j < n; j++) {
                if (seen.count(s[j])) break;
                seen.insert(s[j]);
                result = max(result, j - i + 1);
            }
        }
        return result;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<string> testCases = {
        "",
        "a",
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "dvdf",
        "anviaj"
    };
    cout << "Longest Substring Without Repeating Characters\n";
    cout << "------------------------------------------------\n";
    for (const string &s : testCases) {
        cout << "Input: \"" << s << "\"\n";
        cout << "  Approach 1 (Sliding Window + Array): "
             << sol.lengthOfLongestSubstring_SlidingWindowArray(s) << "\n";
        cout << "  Approach 2 (Sliding Window + String): "
             << sol.lengthOfLongestSubstring_SlidingWindowString(s) << "\n";
        cout << "  Approach 3 (Brute Force): "
             << sol.lengthOfLongestSubstring_BruteForce(s) << "\n";
        cout << "------------------------------------------------\n";
    }
    return 0;
}
