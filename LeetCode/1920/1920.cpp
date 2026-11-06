#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> Result;
        for (int i = 0; i < n; i++) {
            Result.push_back(nums[nums[i]]);
        }
        return Result;
    }
};
int main() {
    Solution sol;
    // Define test cases
    vector<vector<int>> testCases = {
        {0, 2, 1, 5, 3, 4},
        {5, 0, 1, 2, 3, 4},
        {1, 0},
        {3, 1, 2, 0}
    };
    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> input = testCases[i];
        vector<int> output = sol.buildArray(input);
        cout << "Test case " << i + 1 << ": ";
        for (int num : output) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}