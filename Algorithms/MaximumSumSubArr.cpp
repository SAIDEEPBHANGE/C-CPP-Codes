#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Method 1: Kadane's Algorithm for Maximum Absolute Sum
    int maxAbsoluteSumKadane(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currMax = 0, currMin = 0;
        for (int i = 0; i < nums.size(); i++) {
            currMax += nums[i];
            currMin += nums[i];
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
            if (currMax < 0) currMax = 0;
            if (currMin > 0) currMin = 0;
        }
        return max(abs(maxSum), abs(minSum));
    }
    // Method 2: Brute Force for Maximum Absolute Sum
    int maxAbsoluteSumBruteForce(vector<int>& nums) {
        int ans = 0;
        // Iterate through all subarrays
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            // Iterate through the subarray starting from index i
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                ans = max(ans, abs(sum));  // Track the maximum absolute sum
            }
        }
        return ans;
    }
    // Method 3: Recursion for Maximum Absolute Sum
    int AllPossible(int i, vector<int>& nums, int sum) {
        if (i >= nums.size()) return abs(sum);  // Base case: return the absolute sum of the current subarray
        // Include current element and calculate max absolute sum
        int includeCurrent = abs(sum + nums[i]);
        // Recursively calculate for the next index
        return max(includeCurrent, AllPossible(i + 1, nums, sum + nums[i]));
    }
    int maxAbsoluteSumRecursion(vector<int>& nums) {
        int ans = 0;
        // Iterate through all starting indices of subarrays
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, AllPossible(i, nums, 0));  // Start the recursion with sum = 0 for each subarray
        }
        return ans;
    }
    // Method to call all methods
    void compareMethods(vector<int>& nums) {
        cout << "Max absolute sum (Kadane's Algorithm): " << maxAbsoluteSumKadane(nums) << endl;
        cout << "Max absolute sum (Brute Force): " << maxAbsoluteSumBruteForce(nums) << endl;
        cout << "Max absolute sum (Recursion): " << maxAbsoluteSumRecursion(nums) << endl;
    }
};
int main() {
    vector<int> vec1 = {1, -3, 2, 3, -4};
    vector<int> vec2 = {2, -5, 1, -4, 3, -2};
    Solution obj;
    cout << "For vec1: {1, -3, 2, 3, -4}" << endl;
    obj.compareMethods(vec1);
    cout << "\nFor vec2: {2, -5, 1, -4, 3, -2}" << endl;
    obj.compareMethods(vec2);
    return 0;
}