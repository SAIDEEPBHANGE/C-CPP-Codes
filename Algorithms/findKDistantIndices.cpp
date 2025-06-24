#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> Result;
        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                int start = max(j - k, 0);
                int end = min(j + k, n - 1);
                if (!Result.empty() && Result.back() >= start) {
                    start = Result.back() + 1;
                }
                for (int i = start; i <= end; i++) {
                    Result.push_back(i);
                }
            }
        }
        return Result;
    }
};
// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int v : vec) cout << v << " ";
    cout << endl;
}
int main() {
    Solution sol;
    // Define test cases: {nums, key, k}
    vector<tuple<vector<int>, int, int>> testCases = {
        {{3, 4, 9, 1, 3, 9, 5}, 9, 1},
        {{2, 2, 2, 2}, 2, 2},
        {{1, 2, 3, 4, 5}, 3, 2},
        {{1, 3, 1, 3, 1}, 3, 0},
        {{1}, 1, 0},
        {{1}, 2, 0}
    };
    // Run test cases
    for (int i = 0; i < testCases.size(); ++i) {
        auto [nums, key, k] = testCases[i];
        cout << "Test Case " << i + 1 << ": nums = [";
        for (int n : nums) cout << n << " ";
        cout << "], key = " << key << ", k = " << k << "\nResult: ";
        vector<int> result = sol.findKDistantIndices(nums, key, k);
        printVector(result);
        cout << "--------------------------\n";
    }
    return 0;
}