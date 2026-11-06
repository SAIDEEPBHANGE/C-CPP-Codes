#include <bits/stdc++.h> // includes all standard libraries
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> setnums;
        for (int i : nums) {
            if (i == k) {
                setnums.insert(i);  // we only need the number equal to k
            }
        }
        // If no such number exists, return -1
        if (setnums.empty()) {
            return -1;
        }
        return setnums.size();
    }
};
int main() {
    Solution sol;
    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    int k1 = 3;
    cout << "Test case 1 result: " << sol.minOperations(nums1, k1) << endl;
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 6;
    cout << "Test case 2 result: " << sol.minOperations(nums2, k2) << endl;
    // Test case 3
    vector<int> nums3 = {5, 6, 7, 8, 9};
    int k3 = 7;
    cout << "Test case 3 result: " << sol.minOperations(nums3, k3) << endl;
    // Test case 4 (empty array)
    vector<int> nums4 = {};
    int k4 = 3;
    cout << "Test case 4 result: " << sol.minOperations(nums4, k4) << endl;
    // Test case 5 (k is present in multiple numbers)
    vector<int> nums5 = {1, 3, 3, 5};
    int k5 = 3;
    cout << "Test case 5 result: " << sol.minOperations(nums5, k5) << endl;
    return 0;
}