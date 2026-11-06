#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original (slightly corrected) version
    vector<int> twoSumOriginal(vector<int>& nums, int target) {
        vector<int> Result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto FindTarget = find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (FindTarget != nums.end()) {
                Result.push_back(i);
                Result.push_back(distance(nums.begin(), FindTarget));
                break;
            }
        }
        return Result;
    }
    // Optimized version using hash map
    vector<int> twoSumOptimized(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
    // Function to test both versions
    void vector_test_cases() {
        vector<pair<vector<int>, int>> testCases = {
            {{2, 7, 11, 15}, 9},
            {{3, 2, 4}, 6},
            {{3, 3}, 6},
            {{1, 5, 3, 6, 7}, 10},
            {{0, 4, 3, 0}, 0}
        };
        for (int i = 0; i < testCases.size(); ++i) {
            auto nums = testCases[i].first;
            auto target = testCases[i].second;
            vector<int> result1 = twoSumOriginal(nums, target);
            vector<int> result2 = twoSumOptimized(nums, target);
            cout << "Test Case #" << i + 1 << ":\n";
            cout << "Input: nums = { ";
            for (int n : nums) cout << n << " ";
            cout << "}, target = " << target << "\n";
            cout << "Original Output: [ ";
            for (int x : result1) cout << x << " ";
            cout << "]\n";
            cout << "Optimized Output: [ ";
            for (int x : result2) cout << x << " ";
            cout << "]\n";
            cout << "Match: " << (result1 == result2 ? "Yes" : "No") << "\n\n";
        }
    }
};
int main() {
    Solution s;
    s.vector_test_cases();
    return 0;
}