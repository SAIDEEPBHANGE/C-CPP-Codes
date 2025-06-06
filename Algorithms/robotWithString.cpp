#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> minChar(n);
        minChar[n - 1] = s[n - 1];
        // Precompute the minimum character from i to the end
        for (int i = n - 2; i >= 0; --i) {
            minChar[i] = min(s[i], minChar[i + 1]);
        }
        stack<char> st;
        string result;
        for (int i = 0; i < n; ++i) {
            st.push(s[i]);
            // Pop from stack while top is <= min character ahead
            while (!st.empty() && (i == n - 1 || st.top() <= minChar[i + 1])) {
                result += st.top();
                st.pop();
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> testCases = {
        "zza",
        "bac",
        "bdda",
        "cab",
        "edcba",
        "leetcode",
        "aabccb"
    };
    for (const auto& test : testCases) {
        cout << "Input: \"" << test << "\" => Output: \"" 
             << sol.robotWithString(test) << "\"" << endl;
    }
    return 0;
}