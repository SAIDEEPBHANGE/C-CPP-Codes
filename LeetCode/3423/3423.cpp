#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original implementation
    int maxAdjacentDistanceOriginal(vector<int>& nums) {
        int Result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            Result = max(Result, abs(nums[i] - nums[(i + 1) % n]));
        }
        return Result;
    }
    // Optimized implementation
    int maxAdjacentDistanceOptimized(const vector<int>& nums) {
        int maxDiff = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            maxDiff = max(maxDiff, abs(nums[i] - nums[i + 1]));
        }
        // Circular check: last and first
        maxDiff = max(maxDiff, abs(nums[n - 1] - nums[0]));
        return maxDiff;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {10, -10, 20, -20},
        {5},
        {100, 100, 100},
        {-1, -5, -3, 0, 2}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i]) cout << num << " ";
        cout << "\n";
        int originalResult = sol.maxAdjacentDistanceOriginal(testCases[i]);
        int optimizedResult = sol.maxAdjacentDistanceOptimized(testCases[i]);
        cout << "Original Result: " << originalResult << "\n";
        cout << "Optimized Result: " << optimizedResult << "\n\n";
    }
    return 0;
}