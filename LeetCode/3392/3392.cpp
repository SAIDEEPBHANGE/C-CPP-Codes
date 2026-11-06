#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (!(nums[i] % 2) && nums[i] / 2 == nums[i + 1] + nums[i - 1])
                result++;
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 4, 3},       // 4 is even, and 4 / 2 == 1 + 3 → count = 1
        {2, 6, 2},       // 6 is even, and 6 / 2 == 2 + 2 → count = 1
        {1, 2, 1},       // 2 / 2 != 1 + 1 → count = 0
        {0, 2, 0},       // 2 is even, 2 / 2 == 0 + 0 → count = 1
        {5, 10, 1, 4, 2} // Only 10 / 2 == 5 + 1 → count = 1
    };
    for (auto& test : testCases) {
        cout << "Input: ";
        for (int n : test) cout << n << " ";
        cout << "=> Count: " << sol.countSubarrays(test) << endl;
    }
    return 0;
}