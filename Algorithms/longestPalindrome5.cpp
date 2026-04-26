#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    /* ---------- Helper Functions ---------- */
    // Iterative palindrome check
    bool isPalindromeIter(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    // Recursive palindrome check
    bool isPalindromeRec(const string &s, int l, int r) {
        if (l >= r) return true;
        if (s[l] != s[r]) return false;
        return isPalindromeRec(s, l + 1, r - 1);
    }
    // Memoized palindrome check
    vector<vector<int>> memo;
    bool isPalindromeMemo(const string &s, int l, int r) {
        if (l >= r) return true;
        if (memo[l][r] != -1) return memo[l][r];
        if (s[l] == s[r])
            return memo[l][r] = isPalindromeMemo(s, l + 1, r - 1);
        return memo[l][r] = 0;
    }
    // Expand around center helper
    int expandFromCenter(const string &s, int l, int r) {
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            l--; r++;
        }
        return r - l - 1;
    }
public:
    /* ---------- Approach 1: Brute Force + Iterative Check ---------- */
    string longestPalindrome_BruteForceIter(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindromeIter(s, i, j) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
    /* ---------- Approach 2: Brute Force + Recursive Check ---------- */
    string longestPalindrome_BruteForceRec(string s) {
        int n = s.size();
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindromeRec(s, i, j) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
    /* ---------- Approach 3: Brute Force + Memoization ---------- */
    string longestPalindrome_Memo(string s) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindromeMemo(s, i, j) && j - i + 1 > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLen);
    }
    /* ---------- Approach 4: Expand Around Center (Optimized) ---------- */
    string longestPalindrome_CenterExpand(string s) {
        int n = s.size();
        if (n == 0) return "";
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int len1 = expandFromCenter(s, i, i);     // odd length
            int len2 = expandFromCenter(s, i, i + 1); // even length
            int len = max(len1, len2);
            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<string> testCases = {
        "babad",
        "cbbd",
        "a",
        "ac",
        "forgeeksskeegfor",
        "abba",
        "abcda"
    };
    for (const string &s : testCases) {
        cout << "Input: " << s << "\n";
        cout << "Brute Force (Iterative):   " 
             << sol.longestPalindrome_BruteForceIter(s) << "\n";
        cout << "Brute Force (Recursive):   " 
             << sol.longestPalindrome_BruteForceRec(s) << "\n";
        cout << "Brute Force (Memoized):    " 
             << sol.longestPalindrome_Memo(s) << "\n";
        cout << "Center Expansion (Optimal):" 
             << sol.longestPalindrome_CenterExpand(s) << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}
