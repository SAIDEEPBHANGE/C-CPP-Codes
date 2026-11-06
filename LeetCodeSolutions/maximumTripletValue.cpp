#include <bits/stdc++.h>  // Includes most of the standard C++ libraries
#define ll long long
using namespace std;
class Solution {
public:
    // Brute force approach (first function)
    long long maximumTripletValueBruteForce(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ans = max(ans, (long long)((nums[i] - nums[j]) * nums[k]));
                }
            }
        }
        return ans;
    }
    // Optimized approach (second function)
    long long maximumTripletValueOptimized(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        ll MaxResult = 0;
        ll MaxDiff = 0;
        ll MaxLeft = 0;
        for (int i = 0; i < n; i++) {
            MaxResult = max<ll>(MaxResult, 1ll * MaxDiff * nums[i]);
            MaxDiff = max<ll>(MaxDiff, (MaxLeft - nums[i]));
            MaxLeft = max<ll>(MaxLeft, nums[i]);
        }
        return MaxResult;
    }
};
int main() {
    Solution solution;
    // Test case 1: nums = [12, 6, 1, 2, 7]
    vector<int> nums1 = {12, 6, 1, 2, 7};
    cout << "Brute Force - Maximum Triplet Value for nums1: " 
         << solution.maximumTripletValueBruteForce(nums1) << endl;
    cout << "Optimized - Maximum Triplet Value for nums1: " 
         << solution.maximumTripletValueOptimized(nums1) << endl;
    // Test case 2: nums = [1, 10, 3, 4, 19]
    vector<int> nums2 = {1, 10, 3, 4, 19};
    cout << "Brute Force - Maximum Triplet Value for nums2: " 
         << solution.maximumTripletValueBruteForce(nums2) << endl;
    cout << "Optimized - Maximum Triplet Value for nums2: " 
         << solution.maximumTripletValueOptimized(nums2) << endl;
    // Test case 3: nums = [1, 2, 3]
    vector<int> nums3 = {1, 2, 3};
    cout << "Brute Force - Maximum Triplet Value for nums3: " 
         << solution.maximumTripletValueBruteForce(nums3) << endl;
    cout << "Optimized - Maximum Triplet Value for nums3: " 
         << solution.maximumTripletValueOptimized(nums3) << endl;
    return 0;
}