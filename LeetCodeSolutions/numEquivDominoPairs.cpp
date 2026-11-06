#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> count;
        int result = 0;
        for (auto& d : dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            result += count[key];
            count[key]++;
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Define test cases
    vector<vector<vector<int>>> testcases = {
        {{1,2}, {2,1}, {3,4}, {5,6}},
        {{1,2}, {1,2}, {1,1}, {1,2}, {2,2}},
        {{1,1}, {1,1}, {1,1}},
        {{1,2}, {2,1}, {2,1}, {1,2}}
    };
    for (int i = 0; i < testcases.size(); ++i) {
        int result = sol.numEquivDominoPairs(testcases[i]);
        cout << "Test case " << i + 1 << ": " << result << " equivalent pairs" << endl;
    }
    return 0;
}