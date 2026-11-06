#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute-force method (for comparison/testing)
    bool isZeroArrayBrute(vector<int> nums, vector<vector<int>>& queries) {
        for (auto& i : queries) {
            for (int j = i[0]; j <= i[1]; j++) {
                if (nums[j])
                    nums[j] -= 1;
            }
        }
        return accumulate(nums.begin(), nums.end(), 0) == 0;
    }
    // Optimized greedy method using difference array
    bool isZeroArrayOptimized(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l]++;
            if (r + 1 < n) diff[r + 1]--;
        }
        int prefix = 0;
        for (int i = 0; i < n; ++i) {
            prefix += diff[i];
            if (nums[i] > prefix)
                return false;
        }
        return true;
    }
};
int main() {
    Solution sol;
    // Vector of test cases: {nums, queries}
    vector<pair<vector<int>, vector<vector<int>>>> testCases = {
        {{3, 1, 2}, {{0, 2}, {1, 2}, {0, 0}}},
        {{1, 2, 1}, {{0, 1}, {1, 2}}},
        {{2, 2, 2}, {{0, 2}, {0, 2}}},
        {{0, 0, 0}, {}},
        {{5, 5, 5}, {{0, 2}, {0, 2}, {0, 2}, {0, 2}, {0, 2}}}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        auto [nums, queries] = testCases[i];
        bool bruteResult = sol.isZeroArrayBrute(nums, queries);
        bool optimizedResult = sol.isZeroArrayOptimized(nums, queries);
        cout << "Test Case #" << i + 1 << ": ";
        if (bruteResult == optimizedResult)
            cout << (optimizedResult ? "YES" : "NO") << "\n";
        else
            cout << "Mismatch! Brute: " << bruteResult << ", Optimized: " << optimizedResult << "\n";
    }
    return 0;
}