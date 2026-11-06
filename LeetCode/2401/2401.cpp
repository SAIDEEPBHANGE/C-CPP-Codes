#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int curr_or = 0;
        int max_len = 0;
        for (int right = 0; right < n; ++right) {
            // While the bitwise AND of the current element and the current OR is non-zero
            while ((curr_or & nums[right]) != 0) {
                // Shrink the window from the left
                curr_or ^= nums[left];
                left++;
            }
            // Include nums[right] in the OR calculation for the window
            curr_or |= nums[right];
            // Update the maximum length
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
int main() {
    Solution sol;
    // Example test case
    vector<int> nums = {1, 3, 8, 48, 10};
    // Get the length of the longest nice subarray
    int result = sol.longestNiceSubarray(nums);
    // Output the result
    cout << "Length of the longest nice subarray: " << result << endl;
    return 0;
}