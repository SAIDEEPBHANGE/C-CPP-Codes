#include <bits/stdc++.h>
using namespace std;
class Solution {
#define ll long long
    ll FindMaxPoints(vector<vector<int>>& questions, int position,
                     vector<ll>& remaing) {
        if (position >= questions.size())
            return 0;
        if (remaing[position] != -1)
            return remaing[position];
        ll excludeQue = FindMaxPoints(questions, position + 1, remaing);
        ll includeQue =
            questions[position][0] +
            FindMaxPoints(questions, position + questions[position][1] + 1,
                          remaing);
        return remaing[position] = max(excludeQue, includeQue);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> memo(n, -1);
        return FindMaxPoints(questions, 0, memo);
    }
};
int main() {
    Solution sol;
    // Test Case 1
    vector<vector<int>> questions1 = {{3,2},{4,3},{4,4},{2,5}};
    cout << "Max Points for Test Case 1: " << sol.mostPoints(questions1) << endl;
    // Test Case 2
    vector<vector<int>> questions2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    cout << "Max Points for Test Case 2: " << sol.mostPoints(questions2) << endl;
    return 0;
}