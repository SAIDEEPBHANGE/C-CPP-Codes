#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Brute Force (DFS for every word)
    bool dfsWord(vector<vector<char>>& board, string& word,
                 int i, int j, int idx) {
        int m = board.size();
        int n = board[0].size();
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] == '#' || board[i][j] != word[idx])
            return false;
        char ch = board[i][j];
        board[i][j] = '#';
        bool found =
            dfsWord(board, word, i - 1, j, idx + 1) ||
            dfsWord(board, word, i + 1, j, idx + 1) ||
            dfsWord(board, word, i, j - 1, idx + 1) ||
            dfsWord(board, word, i, j + 1, idx + 1);
        board[i][j] = ch;
        return found;
    }
    vector<string> findWordsBruteForce(
        vector<vector<char>>& board,
        vector<string>& words) {
        vector<string> ans;
        for (string& word : words) {
            bool found = false;
            for (int i = 0; i < board.size() && !found; i++) {
                for (int j = 0; j < board[0].size() && !found; j++) {
                    if (board[i][j] == word[0]) {
                        found = dfsWord(board, word, i, j, 0);
                    }
                }
            }
            if (found)
                ans.push_back(word);
        }
        return ans;
    }
    // Approach 2: Trie + DFS (Optimized)
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
            word = "";
        }
    };
    TrieNode* root;
    int m, n;
    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }
    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {
        char ch = board[i][j];
        if (ch == '#' || !node->children[ch - 'a'])
            return;
        node = node->children[ch - 'a'];
        // Found a complete word
        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }
        // Mark current cell as visited
        board[i][j] = '#';
        // Explore four directions
        if (i > 0)
            dfs(board, i - 1, j, node, ans);
        if (i < m - 1)
            dfs(board, i + 1, j, node, ans);
        if (j > 0)
            dfs(board, i, j - 1, node, ans);
        if (j < n - 1)
            dfs(board, i, j + 1, node, ans);
        // Backtrack
        board[i][j] = ch;
    }
    vector<string> findWordsTrie(
        vector<vector<char>>& board,
        vector<string>& words) {
        if (board.empty() || board[0].empty())
            return {};
        root = new TrieNode();
        m = board.size();
        n = board[0].size();
        for (string& word : words)
            insert(word);
        vector<string> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }
        return ans;
    }
};
// Helper function to print results
void printResult(const string& approach, vector<string> ans) {
    sort(ans.begin(), ans.end());
    cout << approach << ": ";
    for (const string& word : ans)
        cout << word << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<vector<vector<char>>, vector<string>>> testCases = {
        {
            {
                {'o', 'a', 'a', 'n'},
                {'e', 't', 'a', 'e'},
                {'i', 'h', 'k', 'r'},
                {'i', 'f', 'l', 'v'}
            },
            {"oath", "pea", "eat", "rain"}
        },
        {
            {
                {'a', 'b'},
                {'c', 'd'}
            },
            {"abcb", "abcd", "acdb", "ab", "ac"}
        },
        {
            {
                {'a', 'a'}
            },
            {"a", "aa", "aaa"}
        }
    };
    Solution sol;
    for (int t = 0; t < testCases.size(); t++) {
        cout << "\nTest Case " << t + 1 << "\n";
        auto board1 = testCases[t].first;
        auto board2 = testCases[t].first;
        auto words = testCases[t].second;
        vector<string> brute =
            sol.findWordsBruteForce(board1, words);
        vector<string> trie =
            sol.findWordsTrie(board2, words);
        printResult("Brute Force", brute);
        printResult("Trie + DFS ", trie);
    }
    return 0;
}
