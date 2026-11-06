#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // First approach
    vector<vector<int>> divideArrayApproach1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> Result;
        int n = nums.size();
        for (int i = 0; i < n - 2; i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                vector<int> temp = {nums.begin() + i, nums.begin() + i + 3};
                Result.push_back(temp);
            }
        }
        if (Result.size() != n / 3)
            return {};
        return Result;
    }
    // Second approach
    vector<vector<int>> divideArrayApproach2(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % 3 != 0) return {};  // Can't divide into groups of 3
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n; i += 3) {
            // Since array is sorted, nums[i+2] is max, nums[i] is min in group
            if (nums[i + 2] - nums[i] > k)
                return {}; // Invalid group, exit early
            result.emplace_back(vector<int>{nums[i], nums[i + 1], nums[i + 2]});
        }
        return result;
    }
};
// Test the two approaches
int main() {
    Solution sol;
    vector<int> test = {1, 3, 4, 8, 7, 9};
    int k = 3;
    // Testing approach 1
    cout << "Approach 1 Result:\n";
    vector<vector<int>> res1 = sol.divideArrayApproach1(test, k);
    for (const auto& group : res1) {
        for (int num : group)
            cout << num << " ";
        cout << endl;
    }
    // Testing approach 2
    cout << "Approach 2 Result:\n";
    vector<vector<int>> res2 = sol.divideArrayApproach2(test, k);
    for (const auto& group : res2) {
        for (int num : group)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}