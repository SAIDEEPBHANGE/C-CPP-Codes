#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Sorting + Sliding Window (Optimal)
    // Time: O(n log n), Space: O(1)
    // ------------------------------------------------------------
    int minimumDifference_sorting(vector<int> nums, int k) {
        if (k <= 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0; i + k - 1 < (int)nums.size(); i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
    // ------------------------------------------------------------
    // Approach 2: Brute Force (Pick all subsets of size k)
    // Time: O(n^k) approx (very slow, only for tiny inputs)
    // Space: O(k)
    // ------------------------------------------------------------
    int minimumDifference_bruteforce(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> curr;
        function<void(int)> dfs = [&](int idx) {
            if ((int)curr.size() == k) {
                int mn = *min_element(curr.begin(), curr.end());
                int mx = *max_element(curr.begin(), curr.end());
                ans = min(ans, mx - mn);
                return;
            }
            if (idx == n) return;
            // pick
            curr.push_back(nums[idx]);
            dfs(idx + 1);
            curr.pop_back();
            // not pick
            dfs(idx + 1);
        };
        dfs(0);
        return ans;
    }
    // ------------------------------------------------------------
    // Approach 3: Sort + Two Pointers (Same idea, different style)
    // Time: O(n log n), Space: O(1)
    // ------------------------------------------------------------
    int minimumDifference_twoPointers(vector<int> nums, int k) {
        if (k <= 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int left = 0;
        for (int right = k - 1; right < (int)nums.size(); right++) {
            ans = min(ans, nums[right] - nums[left]);
            left++;
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<pair<vector<int>, int>> testCases = {
        {{9, 4, 1, 7}, 2},
        {{90}, 1},
        {{1, 3, 6, 10, 15}, 3},
        {{5, 5, 5, 5}, 2},
        {{1, 100, 200, 300}, 2}
    };
    for (int i = 0; i < (int)testCases.size(); i++) {
        auto nums = testCases[i].first;
        int k = testCases[i].second;
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Scores: ";
        for (int x : nums) cout << x << " ";
        cout << "\nK = " << k << "\n";
        cout << "Approach 1 (Sorting + Sliding Window): "
             << sol.minimumDifference_sorting(nums, k) << "\n";
        if (nums.size() <= 10) {
            cout << "Approach 2 (Brute Force): "
                 << sol.minimumDifference_bruteforce(nums, k) << "\n";
        } else {
            cout << "Approach 2 (Brute Force): Skipped (Too Large)\n";
        }
        cout << "Approach 3 (Two Pointers): "
             << sol.minimumDifference_twoPointers(nums, k) << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}
