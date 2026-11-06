#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n > 0) {
            for (int i = 1; i < n; i++) {
                nums[i - 1] = (nums[i] + nums[i - 1]) % 10;
            }
            n--;
        }
        return nums[0];
    }
};
int main() {
    Solution sol;
    // Vector of test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},      // Expected: 8
        {5},                 // Expected: 5
        {9, 4, 6, 7},        // Expected: 0
        {0, 0, 0, 0},        // Expected: 0
        {1, 1, 1, 1, 1},     // Expected: 5
        {9, 9, 9, 9, 9, 9},  // Expected: 6
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> test = testCases[i];
        int result = sol.triangularSum(test);
        cout << "Test Case " << i + 1 << ": Result = " << result << endl;
    }
    return 0;
}
