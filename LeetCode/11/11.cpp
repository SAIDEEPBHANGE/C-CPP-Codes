#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {1,8,6,2,5,4,8,3,7}, // Expected: 49
        {1,1},               // Expected: 1
        {4,3,2,1,4},         // Expected: 16
        {1,2,1},             // Expected: 2
        {2,3,10,5,7,8,9},    // Expected: 36
        {1,3,2,5,25,24,5}    // Expected: 24
    };
    for (int i = 0; i < testCases.size(); ++i) {
        int result = sol.maxArea(testCases[i]);
        cout << "Test case " << i + 1 << ": ";
        for (int h : testCases[i]) cout << h << " ";
        cout << "\nMax area: " << result << "\n\n";
    }
    return 0;
}
