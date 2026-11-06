#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute-force approach
    long long countSubarraysBruteForce(vector<int>& nums, int k) {
        long long result = 0;
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == maxx)
                    count++;
                if (count >= k) {
                    result += (n - j);
                    break;
                }
            }
        }
        return result;
    }
    // Optimized sliding window approach
    long long countSubarraysOptimized(vector<int>& nums, int k) {
        long long result = 0;
        int n = nums.size();
        int maxx = *max_element(nums.begin(), nums.end());
        int left = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxx)
                count++;
            while (count >= k) {
                result += (n - i);
                if (nums[left] == maxx)
                    count--;
                left++;
            }
        }
        return result;
    }
    // Wrapper to run both methods on test cases
    void runTestCases(const vector<pair<vector<int>, int>>& testCases) {
        for (size_t i = 0; i < testCases.size(); ++i) {
            const auto& [nums, k] = testCases[i];
            cout << "Test Case " << i + 1 << ":\n";
            cout << "Input: nums = ";
            for (int num : nums) cout << num << " ";
            cout << ", k = " << k << "\n";
            long long brute = countSubarraysBruteForce(const_cast<vector<int>&>(nums), k);
            long long optimized = countSubarraysOptimized(const_cast<vector<int>&>(nums), k);
            cout << "Brute-force Output: " << brute << "\n";
            cout << "Optimized Output:   " << optimized << "\n";
            cout << (brute == optimized ? "✅ Outputs match\n" : "❌ Outputs do not match\n");
            cout << "-------------------------\n";
        }
    }
};
int main() {
    Solution solution;
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 2, 3, 3}, 2},
        {{1, 4, 2, 4, 4}, 3},
        {{5, 5, 5, 5, 5}, 1},
        {{1, 2, 3, 4, 5}, 1},
        {{2, 2, 2, 1, 2}, 4}
    };
    solution.runTestCases(testCases);
    return 0;
}