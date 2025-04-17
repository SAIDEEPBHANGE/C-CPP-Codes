#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Original brute-force method
    int countPairsBruteForce(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[i] == nums[j]) && ((i * j) % k == 0)) {
                    result++;
                }
            }
        }
        return result;
    }
    // Optimized method using hashmap
    int countPairsOptimized(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> indexMap;
        int result = 0;
        // Group indices by value
        for (int i = 0; i < nums.size(); i++) {
            indexMap[nums[i]].push_back(i);
        }
        // Check (i * j) % k == 0 within each group
        for (auto& entry : indexMap) {
            const vector<int>& indices = entry.second;
            int size = indices.size();
            for (int i = 0; i < size; ++i) {
                for (int j = i + 1; j < size; ++j) {
                    if ((indices[i] * indices[j]) % k == 0) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
int main() {
    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;
    Solution sol;
    int bruteForceResult = sol.countPairsBruteForce(nums, k);
    int optimizedResult = sol.countPairsOptimized(nums, k);
    cout << "Brute-force result: " << bruteForceResult << endl;
    cout << "Optimized result: " << optimizedResult << endl;
    return 0;
}