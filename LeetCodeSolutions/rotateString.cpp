#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Concatenation + find()
    bool approach1(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string temp = s + s;
        return temp.find(goal) != string::npos;
    }

    // Approach 2: Manual rotation check
    bool approach2(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();

        for (int shift = 0; shift < n; shift++) {
            bool match = true;
            for (int i = 0; i < n; i++) {
                if (s[(i + shift) % n] != goal[i]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }

    // Approach 3: Using deque rotation
    bool approach3(string s, string goal) {
        if (s.size() != goal.size()) return false;

        deque<char> dq(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            // rotate left
            char front = dq.front();
            dq.pop_front();
            dq.push_back(front);

            string rotated(dq.begin(), dq.end());
            if (rotated == goal) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<pair<string, string>> testCases = {
        {"abcde", "cdeab"},
        {"abcde", "abced"},
        {"", ""},
        {"a", "a"},
        {"waterbottle", "erbottlewat"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        string s = testCases[i].first;
        string goal = testCases[i].second;

        cout << "Test Case " << i + 1 << ":\n";
        cout << "s = \"" << s << "\", goal = \"" << goal << "\"\n";

        bool res1 = sol.approach1(s, goal);
        bool res2 = sol.approach2(s, goal);
        bool res3 = sol.approach3(s, goal);

        cout << "Approach 1 (Concatenation + find): " << (res1 ? "true" : "false") << "\n";
        cout << "Approach 2 (Manual rotation): " << (res2 ? "true" : "false") << "\n";
        cout << "Approach 3 (Deque rotation): " << (res3 ? "true" : "false") << "\n";

        cout << "-----------------------------------\n";
    }

    return 0;
}