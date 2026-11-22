#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: BFS (Optimal)
    // Time: O(N * L * 26 * L)
    // Space: O(N * L)
    int ladderLengthBFS(string beginWord, string endWord,
                        vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();
            if (word == endWord) {
                return steps;
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch : alpha) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                        // Mark visited immediately.
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
    // Approach 2: BFS using level-by-level traversal
    // Time: O(N * L * 26 * L)
    // Space: O(N * L)
    int ladderLengthLevelBFS(string beginWord, string endWord,
                             vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        int steps = 1;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return steps;
                }
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char ch : alpha) {
                        word[i] = ch;
                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            steps++;
        }
        return 0;
    }
    // Approach 3: Bidirectional BFS
    // Time: Typically faster than standard BFS.
    // Space: O(N * L)
    int ladderLengthBidirectionalBFS(string beginWord, string endWord,
                                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        unordered_set<string> beginSet = {beginWord};
        unordered_set<string> endSet = {endWord};
        st.erase(beginWord);
        st.erase(endWord);
        int steps = 1;
        string alpha = "abcdefghijklmnopqrstuvwxyz";
        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier.
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
            unordered_set<string> nextSet;
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char ch : alpha) {
                        word[i] = ch;
                        if (endSet.find(word) != endSet.end()) {
                            return steps + 1;
                        }
                        if (st.find(word) != st.end()) {
                            nextSet.insert(word);
                            st.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            beginSet = move(nextSet);
            steps++;
        }
        return 0;
    }
    // Approach 4: DFS + Backtracking
    // Exponential in the worst case.
    // Useful for understanding exhaustive search, not recommended
    // for the shortest-path problem on large inputs.
    int ladderLengthDFS(string beginWord, string endWord,
                        vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return 0;
        }
        unordered_set<string> visited;
        int ans = INT_MAX;
        function<void(string, int)> dfs =
            [&](string word, int steps) {
                if (steps >= ans) {
                    return;
                }
                if (word == endWord) {
                    ans = steps;
                    return;
                }
                visited.insert(word);
                string alpha = "abcdefghijklmnopqrstuvwxyz";
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char ch : alpha) {
                        word[i] = ch;
                        if (st.find(word) != st.end() &&
                            !visited.count(word)) {
                            dfs(word, steps + 1);
                        }
                    }
                    word[i] = original;
                }
                visited.erase(word);
            };
        dfs(beginWord, 1);
        return ans == INT_MAX ? 0 : ans;
    }
};
// Main function: Compare all approaches on identical test cases.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    struct TestCase {
        string beginWord;
        string endWord;
        vector<string> wordList;
    };
    vector<TestCase> testCases = {
        {
            "hit", "cog",
            {"hot", "dot", "dog", "lot", "log", "cog"}
        },
        {
            "hit", "cog",
            {"hot", "dot", "dog", "lot", "log"}
        },
        {
            "a", "c",
            {"a", "b", "c"}
        },
        {
            "hot", "dog",
            {"hot", "dog"}
        },
        {
            "red", "tax",
            {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"}
        }
    };
    for (int i = 0; i < testCases.size(); i++) {
        string beginWord = testCases[i].beginWord;
        string endWord = testCases[i].endWord;
        vector<string> wordList = testCases[i].wordList;
        cout << "\n====================================\n";
        cout << "Test Case " << i + 1 << "\n";
        cout << "Begin Word: " << beginWord << "\n";
        cout << "End Word: " << endWord << "\n";
        cout << "------------------------------------\n";
        cout << "BFS: "
             << sol.ladderLengthBFS(beginWord, endWord, wordList)
             << "\n";
        cout << "Level Order BFS: "
             << sol.ladderLengthLevelBFS(beginWord, endWord, wordList)
             << "\n";
        cout << "Bidirectional BFS: "
             << sol.ladderLengthBidirectionalBFS(beginWord, endWord, wordList)
             << "\n";
        cout << "DFS + Backtracking: "
             << sol.ladderLengthDFS(beginWord, endWord, wordList)
             << "\n";
    }
    cout << "\n====================================\n";
    return 0;
}
