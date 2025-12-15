#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute-force O(n^2) solution
    int longestSubarrayBruteForce(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int preSum = 0;
            int currSum = 0;
            int repeatZero = 0;
            for (int j = i; j < n; j++) {
                if (repeatZero == 2) {
                    break;
                }
                if (nums[j] == 0)
                    repeatZero++;
                if (repeatZero == 1) {
                    currSum += nums[j];
                } else {
                    preSum += nums[j];
                }
            }
            if (repeatZero == 0)
                currSum = -1;
            result = max(result, currSum + preSum);
        }
        return result;
    }
    // Optimized sliding window O(n) solution
    int longestSubarrayOptimized(vector<int>& nums) {
        int left = 0, right = 0;
        int zeroCount = 0;
        int maxLen = 0;
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > 1) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left);  // because we have to delete one element
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 1, 0, 1},
        {1, 1, 1},
        {0, 1, 1, 1, 0, 1, 1, 0, 1},
        {0, 0, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 0, 1, 1, 1, 0, 1, 1},
        {1},
        {0},
        {1, 0, 1, 1, 1, 0, 1}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> test = testCases[i];
        cout << "Test case " << i + 1 << ": ";
        for (int num : test) cout << num << " ";
        cout << "\n";
        int brute = sol.longestSubarrayBruteForce(test);
        int opt = sol.longestSubarrayOptimized(test);
        cout << "  Brute-force result: " << brute << "\n";
        cout << "  Optimized result  : " << opt << "\n";
        if (brute != opt) {
            cout << "  ❌ Mismatch detected!\n";
        } else {
            cout << "  ✅ Results match\n";
        }
        cout << "-----------------------------\n";
    }
    return 0;
}
