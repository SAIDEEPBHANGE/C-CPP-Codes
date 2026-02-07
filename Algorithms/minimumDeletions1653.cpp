#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Greedy / One-pass DP (Optimal)
    // Time: O(n), Space: O(1)
    int minimumDeletionsGreedy(const string &s) {
        int deletions = 0;
        int b_count = 0;
        for (char ch : s) {
            if (ch == 'b') {
                b_count++;
            } else { // ch == 'a'
                deletions = min(deletions + 1, b_count);
            }
        }
        return deletions;
    }

    // Approach 2: Prefix-Suffix counting
    // For every split, count b's on the left + a's on the right
    // Time: O(n), Space: O(n)
    int minimumDeletionsPrefixSuffix(const string &s) {
        int n = s.size();
        vector<int> prefixB(n + 1, 0);
        vector<int> suffixA(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixB[i + 1] = prefixB[i] + (s[i] == 'b');
        }
        for (int i = n - 1; i >= 0; i--) {
            suffixA[i] = suffixA[i + 1] + (s[i] == 'a');
        }

        int ans = n;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, prefixB[i] + suffixA[i]);
        }
        return ans;
    }

    // Approach 3: Dynamic Programming
    // dp[i] = minimum deletions to make s[0..i-1] balanced
    // Time: O(n), Space: O(n)
    int minimumDeletionsDP(const string &s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        int b_count = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'b') {
                dp[i] = dp[i - 1];
                b_count++;
            } else { // 'a'
                dp[i] = min(dp[i - 1] + 1, b_count);
            }
        }
        return dp[n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<string> testCases = {
        "aababbab",
        "bbaaaaabb",
        "aaaa",
        "bbbb",
        "ababab",
        "baab"
    };

    cout << "Minimum Deletions to Make String Balanced\n";
    cout << "----------------------------------------\n";

    for (const auto &s : testCases) {
        cout << "String: " << s << "\n";
        cout << "Greedy Approach:        " << sol.minimumDeletionsGreedy(s) << "\n";
        cout << "Prefix-Suffix Approach: " << sol.minimumDeletionsPrefixSuffix(s) << "\n";
        cout << "DP Approach:            " << sol.minimumDeletionsDP(s) << "\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}
