#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];
            if (mapST.count(c1)) {
                if (mapST[c1] != c2)
                    return false;
            } else {
                if (mapTS.count(c2))
                    return false;
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<pair<string, string>> testCases = {
        {"egg", "add"},     // true
        {"foo", "bar"},     // false
        {"paper", "title"}, // true
        {"ab", "aa"},       // false
        {"", ""},           // true
        {"badc", "baba"}    // false
    };
    for (auto& test : testCases) {
        cout << "s = \"" << test.first << "\", t = \"" << test.second << "\" => ";
        cout << (sol.isIsomorphic(test.first, test.second) ? "true" : "false") << endl;
    }
    return 0;
}