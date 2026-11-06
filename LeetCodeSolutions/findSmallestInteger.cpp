#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> count;
        for (int num : nums) {
            int mod = ((num % value) + value) % value; // ensures non-negative modulo
            count[mod]++;
        }
        int k = 0;
        while (true) {
            int mod = k % value;
            if (count[mod] == 0) {
                return k;
            }
            count[mod]--;
            k++;
        }
    }
};
int main() {
    Solution sol;
    // Test cases: vector of pairs {nums, value}
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5}, 3},
        {{0, 1, 2, 3}, 2},
        {{-1, -2, -3, 1}, 4},
        {{5, 7, 8, 10}, 2},
        {{0, 0, 0, 0}, 1},
        {{1, 3, 5, 7, 9}, 2},
        {{-5, -10, -15}, 5}
    };
    for (size_t i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int value = testCases[i].second;
        int result = sol.findSmallestInteger(nums, value);
        cout << "Test Case " << i + 1 << ": Result = " << result << endl;
    }
    return 0;
}
