#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 🔸 Your original implementation
    int minOperations(vector<int>& nums, int k) {
        int Ops = 0;
        for (int i : nums) {
            if (i < k) {
                Ops++;
            }
        }
        return Ops;
    }
    // 🔹 Optimal STL version using count_if
    int minOperationsOptimal(vector<int>& nums, int k) {
        return count_if(nums.begin(), nums.end(), [&](int x) {
            return x < k;
        });
    }
};
int main() {
    Solution sol;
    vector<pair<vector<int>, int>> testCases = {
        {{1, 3, 5, 7}, 4},      // Output: 2 (1,3)
        {{10, 20, 30}, 15},     // Output: 1 (10)
        {{5, 6, 7, 8}, 5},      // Output: 0
        {{2, 2, 2, 2}, 3},      // Output: 4
        {{1, 2, 3, 4, 5}, 6},   // Output: 5
    };
    for (auto &[nums, k] : testCases) {
        cout << "nums = [";
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
        }
        cout << "], k = " << k << "\n";
        cout << "  Your Method Result:    " << sol.minOperations(nums, k) << "\n";
        cout << "  Optimal Method Result: " << sol.minOperationsOptimal(nums, k) << "\n\n";
    }
    return 0;
}