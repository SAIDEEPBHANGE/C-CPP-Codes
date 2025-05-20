#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Function to calculate the sum of squares for valid indices
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                result += nums[i] * nums[i];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Define multiple test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4},
        {2, 7, 1, 8, 2, 8},
        {10, 20, 30},
        {5},
        {1, 1, 1, 1, 1, 1}
    };

    // Process each test case
    for (int i = 0; i < testCases.size(); ++i) {
        int result = sol.sumOfSquares(testCases[i]);
        cout << "Test Case #" << i + 1 << " → Sum of squares: " << result << endl;
    }

    return 0;
}
