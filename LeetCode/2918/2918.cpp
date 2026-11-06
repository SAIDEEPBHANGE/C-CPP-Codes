#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    #define ll long long
    // Helper function to calculate sum of the vector and count zeros
    void CalculateVector(vector<int>& arr, ll& arrSum, int& arrZero) {
        for (int i : arr) {
            if (i == 0) {
                arrSum++;
                arrZero++;
            } else {
                arrSum += i;
            }
        }
    }
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long result = -1;
        ll nums1Sum = 0;
        int nums1Zero = 0;
        CalculateVector(nums1, nums1Sum, nums1Zero);
        ll nums2Sum = 0;
        int nums2Zero = 0;
        CalculateVector(nums2, nums2Sum, nums2Zero);
        // Check the conditions to return the result
        if ((nums1Sum < nums2Sum && nums1Zero == 0) ||
            (nums1Sum > nums2Sum && nums2Zero == 0)) {
            return -1;
        }
        return max<ll>(nums1Sum, nums2Sum);
    }
};
int main() {
    Solution sol;
    // Test cases for minSum
    vector<vector<int>> test_cases = {
        {1, 2, 3, 0, 5},    // Expected output: 11 (nums1Sum is 11, nums2Sum is 10)
        {0, 0, 0},          // Expected output: 3 (nums1Sum is 3, nums2Sum is 3)
        {5, 10, 15},        // Expected output: 30 (nums1Sum is 30, nums2Sum is 20)
        {1, 2, 3, 4},       // Expected output: 10 (nums1Sum is 10, nums2Sum is 6)
        {0, 0},             // Expected output: 2 (nums1Sum is 2, nums2Sum is 2)
        {-1, -2, 0, 3}      // Expected output: 3 (nums1Sum is 0, nums2Sum is 3)
    };
    // Running test cases
    for (auto& test_case : test_cases) {
        vector<int> nums1 = test_case;
        vector<int> nums2 = test_case;
        long long result = sol.minSum(nums1, nums2);
        cout << "Test case: ";
        for (int num : nums1) {
            cout << num << " ";
        }
        cout << "\nResult: " << result << "\n\n";
    }
    return 0;
}