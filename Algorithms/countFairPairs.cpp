#include <bits/stdc++.h>
using namespace std;
class Solution {
#define ll long long
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        ll count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            count += (right - left);
        }
        return count;
    }
};
int main() {
    Solution sol;
    vector<pair<vector<int>, pair<int, int>>> testCases = {
        {{1, 3, 5, 7, 9}, {8, 10}},          // Expected: 2 -> (1+7, 3+5)
        {{0, 1, 7, 4, 4, 5}, {3, 6}},        // Expected: 6
        {{-1, 0, 1, 2}, {0, 2}},             // Expected: 4 -> (-1+1, -1+2, 0+1, 0+2)
        {{5, 5, 5, 5}, {10, 10}},            // Expected: 6 -> all pairs of (5,5)
        {{1, 2, 3, 4}, {7, 8}},              // Expected: 1 -> only (3+4)
    };
    int testNum = 1;
    for (auto& test : testCases) {
        vector<int> nums = test.first;
        int lower = test.second.first;
        int upper = test.second.second;
        long long result = sol.countFairPairs(nums, lower, upper);
        cout << "Test Case " << testNum++ << ": ";
        cout << "Result = " << result << endl;
    }
    return 0;
}