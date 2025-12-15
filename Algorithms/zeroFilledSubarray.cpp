#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0, count = 0;
        for (int num : nums) {
            if (num == 0)
                res += ++count;
            else
                count = 0;
        }
        return res;
    }
};
int main() {
    Solution sol;
    // Vector of test cases
    vector<vector<int>> testCases = {
        {0, 0, 0},              // Expected: 6 ([0], [0], [0], [0,0], [0,0], [0,0,0])
        {1, 0, 2, 0, 0},        // Expected: 3 ([0], [0], [0,0])
        {0, 1, 0, 1, 0},        // Expected: 3 ([0], [0], [0])
        {1, 2, 3},              // Expected: 0
        {0},                    // Expected: 1
        {},                     // Expected: 0
        {0, 0, 1, 0, 0, 0},     // Expected: 10 ([0],[0],[0,0],[0],[0,0],[0,0,0])
        {0, 0, 0, 0, 0}         // Expected: 15
    };
    // Run and print each test case
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int>& nums = testCases[i];
        cout << "Test case " << i + 1 << ": ";
        for (int n : nums) cout << n << " ";
        cout << "\nResult: " << sol.zeroFilledSubarray(nums) << "\n\n";
    }
    return 0;
}
