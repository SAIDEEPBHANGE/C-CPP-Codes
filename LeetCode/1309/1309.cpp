#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        int i = 0;
        int n = s.size();
        while (i < n) {
            // Check for a '#' pattern like "10#", "23#"
            if (i + 2 < n && s[i + 2] == '#') {
                int num = stoi(s.substr(i, 2)); // e.g. "10"
                result += ('a' + num - 1);       // 'j' = 'a' + 9
                i += 3; // Move past the whole "10#"
            } else {
                int num = s[i] - '0';           // Single digit
                result += ('a' + num - 1);
                i++;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> testCases = {
        "10#11#12",       // jkab
        "1326#",          // acz
        "25#",            // y
        "123456789",      // abcdefghi
        "20#6#4#1",       // tfdad
        "26#11#418#5",    // zkabhe
    };
    for (const string &s : testCases) {
        cout << "Input: " << s << " => Output: " << sol.freqAlphabets(s) << endl;
    }
    return 0;
}