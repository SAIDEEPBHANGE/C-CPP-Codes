#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        // Build frequency map
        for (int num : nums) {
            ++freqMap[num];
        }
        int maxLength = 0;
        for (const auto& [key, count] : freqMap) {
            if (freqMap.count(key + 1)) {
                maxLength = max(maxLength, count + freqMap[key + 1]);
            }
        }
        return maxLength;
    }
};
int main() {
    Solution sol;
    // Test case 1
    vector<int> nums1 = {1, 3, 2, 2, 5, 2, 3, 7};
    cout << "Test case 1: " << sol.findLHS(nums1) << endl; // Expected: 5
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Test case 2: " << sol.findLHS(nums2) << endl; // Expected: 2
    // Test case 3
    vector<int> nums3 = {1, 1, 1, 1};
    cout << "Test case 3: " << sol.findLHS(nums3) << endl; // Expected: 0
    // Test case 4
    vector<int> nums4 = {1, 4, 5, 6, 7, 2, 3, 2, 1};
    cout << "Test case 4: " << sol.findLHS(nums4) << endl; // Expected: 4
    // Test case 5 (edge case)
    vector<int> nums5 = {};
    cout << "Test case 5: " << sol.findLHS(nums5) << endl; // Expected: 0
    return 0;
}