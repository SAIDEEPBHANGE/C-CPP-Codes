#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        vector<int> indexes = {-1};
        vector<char> symbols = {'L'};
        for (int i = 0; i < N; ++i) {
            if (dominoes[i] != '.') {
                indexes.push_back(i);
                symbols.push_back(dominoes[i]);
            }
        }
        indexes.push_back(N);
        symbols.push_back('R');
        vector<char> ans(dominoes.begin(), dominoes.end());
        for (size_t index = 0; index + 1 < indexes.size(); ++index) {
            int i = indexes[index], j = indexes[index + 1];
            char x = symbols[index], y = symbols[index + 1];
            if (x == y) {
                for (int k = i + 1; k < j; ++k) {
                    ans[k] = x;
                }
            } else if (x == 'R' && y == 'L') {
                for (int k = i + 1; k < j; ++k) {
                    if (k - i == j - k)
                        ans[k] = '.';
                    else if (k - i < j - k)
                        ans[k] = 'R';
                    else
                        ans[k] = 'L';
                }
            }
        }
        return string(ans.begin(), ans.end());
    }
};
int main() {
    Solution sol;
    vector<string> test_cases = {
        ".L.R...LR..L..",
        "RR.L",
        "R....L",
        "R.R.L",
        "...",
        "L.....R",
        "R.......L",
        "L.R.L"
    };
    for (const string& test : test_cases) {
        cout << "Input:    " << test << endl;
        cout << "Output:   " << sol.pushDominoes(test) << endl;
        cout << "---------------------" << endl;
    }
    return 0;
}