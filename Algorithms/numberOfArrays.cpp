#include <bits/stdc++.h>
using namespace std;
class Solution {
#define ll long long
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        ll HigherBound = 0;
        ll LowerBound = 0;
        ll PrefixSum = 0;
        for (int& i : differences) {
            PrefixSum += i;
            HigherBound = max(HigherBound, PrefixSum);
            LowerBound = min(LowerBound, PrefixSum);
        }
        int result = (upper - lower) - (HigherBound - LowerBound) + 1;
        return result > 0 ? result : 0;
    }
};
int main() {
    Solution sol;
    // Define a vector of test cases as tuples: {differences, lower, upper}
    vector<tuple<vector<int>, int, int>> testCases = {
        {{1, -3, 4}, 1, 6},
        {{3, -4, 5, 1, -2}, -4, 5},
        {{4, 7, 10}, -100, 100},
        {{-2, -1, -3}, -10, 0},
        {{}, 0, 0}  // Edge case: empty differences
    };
    // Execute each test case
    for (int i = 0; i < testCases.size(); ++i) {
        auto& [differences, lower, upper] = testCases[i];
        int result = sol.numberOfArrays(differences, lower, upper);
        cout << "Test Case " << i + 1 << ": ";
        cout << "Result = " << result << endl;
    }
    return 0;
}