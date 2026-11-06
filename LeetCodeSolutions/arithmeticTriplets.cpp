#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Brute-force: O(n^3)
    int arithmeticTripletsBruteForce(vector<int>& nums, int diff) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j] - nums[i] != diff)
                    continue;
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] - nums[j] != diff)
                        continue;
                    result++;
                }
            }
        }
        return result;
    }
    // Optimized: O(n)
    int arithmeticTripletsOptimized(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int result = 0;
        for (int num : nums) {
            if (s.count(num + diff) && s.count(num + 2 * diff)) {
                result++;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Test cases: vector of (nums vector, diff)
    vector<pair<vector<int>, int>> testcases = {
        {{0, 1, 4, 6, 7, 10}, 3},
        {{1, 2, 3, 4, 5}, 1},
        {{1, 3, 5, 7, 9}, 2},
        {{10, 20, 30, 40}, 10},
        {{1, 5, 9, 13}, 4}
    };
    for (int i = 0; i < testcases.size(); ++i) {
        vector<int> nums = testcases[i].first;
        int diff = testcases[i].second;
        int brute = sol.arithmeticTripletsBruteForce(nums, diff);
        int optimized = sol.arithmeticTripletsOptimized(nums, diff);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "  Input: [";
        for (int j = 0; j < nums.size(); ++j) {
            cout << nums[j] << (j < nums.size() - 1 ? ", " : "");
        }
        cout << "], diff = " << diff << endl;
        cout << "  Brute-force Result: " << brute << endl;
        cout << "  Optimized Result  : " << optimized << endl;
        cout << "-------------------------------------\n";
    }
    return 0;
}