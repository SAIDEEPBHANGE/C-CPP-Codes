#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDiff(int num) {
        string MaxString = to_string(num);
        string MinString = MaxString;
        // Maximize: Replace first digit not '9' with '9'
        size_t idx = MaxString.find_first_not_of('9');
        if (idx != string::npos) {
            char toReplace = MaxString[idx];
            for (char& c : MaxString) {
                if (c == toReplace) c = '9';
            }
        }
        // Minimize: Replace first digit not '1' or '0'
        for (size_t i = 0; i < MinString.size(); ++i) {
            char ch = MinString[i];
            if (ch != '1' && ch != '0') {
                char replacement = (i == 0) ? '1' : '0';
                for (char& c : MinString) {
                    if (c == ch) c = replacement;
                }
                break;
            }
        }
        return stoi(MaxString) - stoi(MinString);
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {
        1101057,   // Expect 8808050
        123456,    // Expect 820000
        9,         // Expect 8
        999999,    // Expect 888888
        1000000,   // Expect 8999999
        1,         // Expect 8
        0          // Expect 9
    };
    for (int num : testCases) {
        int result = sol.maxDiff(num);
        cout << "Input: " << num << " → Max Difference: " << result << endl;
    }
    return 0;
}