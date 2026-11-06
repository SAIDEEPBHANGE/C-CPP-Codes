#include <bits/stdc++.h>
using namespace std;
/*
 LeetCode: Maximize the Area of Square Hole in Grid
 We demonstrate multiple approaches inside the same Solution class.
*/
class Solution {
public:
    /*------------------------------------------------------------
     Approach 1: Sorting + Longest Consecutive Sequence (Standard)
     Time: O(H log H + V log V)
     Space: O(1) extra
    ------------------------------------------------------------*/
    int maximizeSquareHoleArea_sorting(
        int n, int m, vector<int> hBars, vector<int> vBars
    ) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxH = 1, maxV = 1, cur = 1;
        for (int i = 1; i < (int)hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1)
                cur++;
            else
                cur = 1;
            maxH = max(maxH, cur);
        }
        cur = 1;
        for (int i = 1; i < (int)vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1)
                cur++;
            else
                cur = 1;
            maxV = max(maxV, cur);
        }
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
    /*------------------------------------------------------------
     Approach 2: Using Sets (Implicit Sorting)
     Time: O(H log H + V log V)
     Space: O(H + V)
    ------------------------------------------------------------*/
    int maximizeSquareHoleArea_set(
        int n, int m, vector<int> hBars, vector<int> vBars
    ) {
        auto longestConsecutive = [](const vector<int>& bars) {
            set<int> s(bars.begin(), bars.end());
            int best = 1, cur = 0, prev = -1;
            for (int x : s) {
                if (x == prev + 1)
                    cur++;
                else
                    cur = 1;
                best = max(best, cur);
                prev = x;
            }
            return best;
        };
        int maxH = longestConsecutive(hBars);
        int maxV = longestConsecutive(vBars);
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
    /*------------------------------------------------------------
     Approach 3: Boolean Marking + Scan
     Time: O(n + m)
     Space: O(n + m)
     (Useful when constraints are small enough)
    ------------------------------------------------------------*/
    int maximizeSquareHoleArea_marking(
        int n, int m, vector<int> hBars, vector<int> vBars
    ) {
        vector<bool> h(n + 2, false), v(m + 2, false);
        for (int x : hBars) h[x] = true;
        for (int x : vBars) v[x] = true;
        auto longest = [](const vector<bool>& arr) {
            int best = 1, cur = 0;
            for (int i = 1; i < (int)arr.size(); i++) {
                if (arr[i])
                    cur++;
                else
                    cur = 0;
                best = max(best, cur + 1);
            }
            return best - 1;
        };
        int maxH = longest(h);
        int maxV = longest(v);
        int side = min(maxH, maxV) + 1;
        return side * side;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    struct TestCase {
        int n, m;
        vector<int> hBars;
        vector<int> vBars;
    };
    vector<TestCase> tests = {
        {5, 5, {2, 3}, {2, 3}},
        {6, 6, {1, 2, 4}, {2, 3, 4}},
        {4, 4, {1}, {3}},
        {8, 8, {2, 3, 4, 6}, {1, 2, 3}}
    };
    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "  Approach 1 (Sorting): "
             << sol.maximizeSquareHoleArea_sorting(
                    tests[i].n, tests[i].m,
                    tests[i].hBars, tests[i].vBars)
             << "\n";
        cout << "  Approach 2 (Set):     "
             << sol.maximizeSquareHoleArea_set(
                    tests[i].n, tests[i].m,
                    tests[i].hBars, tests[i].vBars)
             << "\n";
        cout << "  Approach 3 (Marking): "
             << sol.maximizeSquareHoleArea_marking(
                    tests[i].n, tests[i].m,
                    tests[i].hBars, tests[i].vBars)
             << "\n\n";
    }
    return 0;
}
