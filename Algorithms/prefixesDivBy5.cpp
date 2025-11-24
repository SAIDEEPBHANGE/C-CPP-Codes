#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int curr = 0;
        for (int b : nums) {
            curr = (curr * 2 + b) % 5;
            ans.push_back(curr == 0);
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    // vector of test cases
    vector<vector<int>> testCases = {
        {0,1,1},
        {1,1,1,1,1},
        {0,0,0},
        {1,0,1,0,1},
        {1,0,0,1,1,0}
    };
    for (auto &tc : testCases) {
        vector<bool> res = sol.prefixesDivBy5(tc);
        for (bool b : res) {
            cout << (b ? "true" : "false") << " ";
        }
        cout << "\n";
    }
    return 0;
}