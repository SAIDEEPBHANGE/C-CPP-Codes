#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int m, n;
    // Approach 1: Brute Force DFS + Backtracking
    bool dfsBrute(vector<vector<char>>& board, string& word,
                  int i, int j, int idx) {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if (board[i][j] != word[idx])
            return false;
        char ch = board[i][j];
        board[i][j] = '#';
        bool found =
            dfsBrute(board, word, i + 1, j, idx + 1) ||
            dfsBrute(board, word, i - 1, j, idx + 1) ||
            dfsBrute(board, word, i, j + 1, idx + 1) ||
            dfsBrute(board, word, i, j - 1, idx + 1);
        board[i][j] = ch;
        return found;
    }
    bool existBrute(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return word.empty();
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfsBrute(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
    // Approach 2: Optimized DFS + Backtracking
    bool dfsOptimized(vector<vector<char>>& board, string& word,
                      int i, int j, int idx) {
        if (idx == word.size())
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        if (board[i][j] != word[idx])
            return false;
        char ch = board[i][j];
        board[i][j] = '#';
        bool found = false;
        if (dfsOptimized(board, word, i + 1, j, idx + 1))
            found = true;
        else if (dfsOptimized(board, word, i - 1, j, idx + 1))
            found = true;
        else if (dfsOptimized(board, word, i, j + 1, idx + 1))
            found = true;
        else if (dfsOptimized(board, word, i, j - 1, idx + 1))
            found = true;
        board[i][j] = ch;
        return found;
    }
    bool existOptimized(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty())
            return word.empty();
        m = board.size();
        n = board[0].size();
        // Impossible if word is longer than total cells
        if (word.size() > m * n)
            return false;
        // Character frequency pruning
        vector<int> freq(128, 0);
        for (auto& row : board) {
            for (char ch : row)
                freq[ch]++;
        }
        for (char ch : word) {
            if (--freq[ch] < 0)
                return false;
        }
        // Start from the less frequent endpoint
        if (freq[word[0]] > freq[word.back()])
            reverse(word.begin(), word.end());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfsOptimized(board, word, i, j, 0))
                        return true;
                }
            }
        }
        return false;
    }
};
// Helper function
void printResult(string approach, bool result) {
    cout << approach << ": "
         << (result ? "true" : "false") << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<vector<vector<char>>, string>> testCases = {
        {
            {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            },
            "ABCCED"
        },
        {
            {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            },
            "SEE"
        },
        {
            {
                {'A', 'B', 'C', 'E'},
                {'S', 'F', 'C', 'S'},
                {'A', 'D', 'E', 'E'}
            },
            "ABCB"
        },
        {
            {
                {'A'}
            },
            "A"
        },
        {
            {
                {'A', 'A'},
                {'A', 'A'}
            },
            "AAAAA"
        },
        {
            {
                {'A', 'B'},
                {'C', 'D'}
            },
            "ACDB"
        }
    };
    Solution sol;
    for (int t = 0; t < testCases.size(); t++) {
        cout << "\n========== Test Case "
             << t + 1 << " ==========\n";
        vector<vector<char>> board1 = testCases[t].first;
        vector<vector<char>> board2 = testCases[t].first;
        string word = testCases[t].second;
        cout << "Word: " << word << "\n";
        bool result1 = sol.existBrute(board1, word);
        bool result2 = sol.existOptimized(board2, word);
        printResult("Approach 1 - Basic DFS", result1);
        printResult("Approach 2 - Optimized DFS", result2);
    }
    return 0;
}
