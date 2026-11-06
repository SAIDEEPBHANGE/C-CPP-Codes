#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = time % (2 * (n - 1));
        if (cycle < n)
            return 1 + cycle;
        else
            return n - (cycle - (n - 1));
    }
};
int main() {
    Solution sol;
    // Define test cases: {n, time}
    vector<pair<int, int>> testCases = {
        {4, 5},
        {3, 2},
        {5, 10},
        {2, 1},
        {6, 15},
        {7, 20}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        int n = testCases[i].first;
        int time = testCases[i].second;
        int result = sol.passThePillow(n, time);
        cout << "Test Case #" << i + 1 << " → n = " << n << ", time = " << time
             << " → Person: " << result << endl;
    }
    return 0;
}