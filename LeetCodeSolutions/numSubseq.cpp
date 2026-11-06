#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int left = 0, right = nums.size() - 1;
        int result = 0;
        // Precompute powers of 2 modulo mod
        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        // Two-pointer approach
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % mod;
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Test Case 1
    vector<int> nums1 = {3, 5, 6, 7};
    int target1 = 9;
    cout << "Test Case 1: " << sol.numSubseq(nums1, target1) << endl; // Expected: 4
    // Test Case 2
    vector<int> nums2 = {3, 3, 6, 8};
    int target2 = 10;
    cout << "Test Case 2: " << sol.numSubseq(nums2, target2) << endl; // Expected: 6
    // Test Case 3
    vector<int> nums3 = {2, 3, 3, 4, 6, 7};
    int target3 = 12;
    cout << "Test Case 3: " << sol.numSubseq(nums3, target3) << endl; // Expected: 61
    // Test Case 4
    vector<int> nums4 = {5, 2, 4, 1, 7, 6, 8};
    int target4 = 16;
    cout << "Test Case 4: " << sol.numSubseq(nums4, target4) << endl; // Output depends on logic
    return 0;
}