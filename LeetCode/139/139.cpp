#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: DFS + Memoization
    bool dfs(string& s, vector<string>& wordDict, int idx,
             vector<int>& dp) {
        if (idx == s.size())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (string word : wordDict) {
            int len = word.size();
            if (idx + len <= s.size() &&
                s.substr(idx, len) == word) {
                if (dfs(s, wordDict, idx + len, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
public:
    // Approach 1: DFS + Memoization
    bool wordBreakDFS(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return dfs(s, wordDict, 0, dp);
    }
    // Approach 2: BFS
    bool wordBreakBFS(string s, vector<string>& wordDict) {
        int n = s.size();
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (idx == n)
                return true;
            for (string word : wordDict) {
                int len = word.size();
                if (idx + len <= n &&
                    s.substr(idx, len) == word &&
                    !visited[idx + len]) {
                    q.push(idx + len);
                    visited[idx + len] = true;
                }
            }
        }
        return false;
    }
    // Approach 3: DP (Tabulation)
    bool wordBreakDP(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (string word : wordDict) {
                int len = word.size();
                if (i >= len &&
                    dp[i - len] &&
                    s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<pair<string, vector<string>>> testCases = {
        {
            "leetcode",
            {"leet", "code"}
        },
        {
            "applepenapple",
            {"apple", "pen"}
        },
        {
            "catsandog",
            {"cats", "dog", "sand", "and", "cat"}
        },
        {
            "aaaaaaa",
            {"aaaa", "aaa"}
        },
        {
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
            {"a", "aa", "aaa", "aaaa", "aaaaa",
             "aaaaaa", "aaaaaaa", "aaaaaaaa",
             "aaaaaaaaa", "aaaaaaaaaa"}
        }
    };
    cout << "Word Break - Approach Comparison\n";
    cout << "=================================\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        string s = testCases[i].first;
        vector<string> wordDict = testCases[i].second;
        bool dfsResult = sol.wordBreakDFS(s, wordDict);
        bool bfsResult = sol.wordBreakBFS(s, wordDict);
        bool dpResult = sol.wordBreakDP(s, wordDict);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "String: " << s << "\n";
        cout << "DFS + Memoization: "
             << (dfsResult ? "true" : "false") << "\n";
        cout << "BFS: "
             << (bfsResult ? "true" : "false") << "\n";
        cout << "DP (Tabulation): "
             << (dpResult ? "true" : "false") << "\n";
        cout << "---------------------------------\n";
    }
    return 0;
}
