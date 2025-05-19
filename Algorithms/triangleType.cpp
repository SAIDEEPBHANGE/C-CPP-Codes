#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // Triangle inequality check
        if (nums[0] + nums[1] <= nums[2])
            return "none";
        if (nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        if (nums[0] == nums[1] || nums[1] == nums[2])
            return "isosceles";
        return "scalene";
    }
};
int main() {
    vector<vector<int>> testcases = {
        {3, 3, 3},    // equilateral
        {3, 4, 5},    // scalene
        {5, 5, 8},    // isosceles
        {1, 2, 3},    // none
        {10, 1, 1}    // none
    };
    Solution sol;
    for (const auto& test : testcases) {
        cout << "Triangle with sides " << test[0] << ", " << test[1] << ", " << test[2]
             << " is " << sol.triangleType(const_cast<vector<int>&>(test)) << endl;
    }
    return 0;
}