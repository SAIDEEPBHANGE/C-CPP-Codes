#include <bits/stdc++.h>
using namespace std;

// Function to check if an array is strictly increasing
bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
    for (int i = start; i < start + k - 1; i++) {
        if (nums[i] >= nums[i + 1]) {
            return false; // Not strictly increasing
        }
    }
    return true; // Strictly increasing
}

// Function to check if two adjacent subarrays of length k are strictly increasing
bool hasIncreasingSubarrays(const vector<int>& nums, int k) {
    int n = nums.size();
    for (int i = 0; i + 2 * k <= n; i++) {
        if (isStrictlyIncreasing(nums, i, k) && isStrictlyIncreasing(nums, i + k, k)) {
            return true;
        }
    }
    return false;
}

int main() {
    // Test cases (vector of pairs)
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5, 6}, 2}, // Expected: true
        {{1, 3, 2, 4, 5, 6}, 2}, // Expected: false
        {{1, 2, 3, 1, 4, 5, 6}, 2}, // Expected: false
        {{1, 2, 3, 4, 5, 6}, 3}, // Expected: true
        {{1, 2, 3, 5, 4, 6, 7}, 2} // Expected: false
    };

    // Run test cases
    for (const auto& testCase : testCases) {
        const auto& nums = testCase.first;
        int k = testCase.second;

        cout << "Array: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << "\nk = " << k << "\n";
        cout << "Result: " << (hasIncreasingSubarrays(nums, k) ? "true" : "false") << "\n\n";
    }

    return 0;
}
