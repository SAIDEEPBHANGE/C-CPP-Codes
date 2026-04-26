#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Sort the array
    // Time: O(n log n), Space: O(1) extra
    int minimumCost_sort(vector<int> nums) {
        sort(nums.begin() + 1, nums.end()); // keep nums[0] fixed
        return nums[0] + nums[1] + nums[2];
    }
    // Approach 2: Linear scan to find two smallest elements after index 0
    // Time: O(n), Space: O(1)
    int minimumCost_linear(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] < first) {
                second = first;
                first = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            }
        }
        return nums[0] + first + second;
    }
    // Approach 3: Using a min-heap
    // Time: O(n), Space: O(n)
    int minimumCost_heap(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i < (int)nums.size(); i++) {
            pq.push(nums[i]);
        }
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        return nums[0] + a + b;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {5, 3, 4, 2},
        {10, 1, 2, 3, 4},
        {7, 6, 5, 4, 3, 2},
        {100, 50, 20, 30, 10}
    };
    for (size_t i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        cout << "Test Case " << i + 1 << ": ";
        cout << "Sort = " << sol.minimumCost_sort(nums) << ", ";
        cout << "Linear = " << sol.minimumCost_linear(nums) << ", ";
        cout << "Heap = " << sol.minimumCost_heap(nums) << "\n";
    }
    return 0;
}
