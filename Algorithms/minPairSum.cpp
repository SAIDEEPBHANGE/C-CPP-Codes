#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* ------------------------------------------------------------
       Approach 1: Greedy + Sorting (Optimal & Standard)
       Time:  O(n log n)
       Space: O(1) extra
       ------------------------------------------------------------ */
    int minPairSum_sort(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }

    /* ------------------------------------------------------------
       Approach 2: Two Pointers after Sorting
       (Same idea, different implementation style)
       Time:  O(n log n)
       Space: O(1) extra
       ------------------------------------------------------------ */
    int minPairSum_twoPointers(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        int ans = 0;

        while (l < r) {
            ans = max(ans, nums[l] + nums[r]);
            l++;
            r--;
        }
        return ans;
    }

    /* ------------------------------------------------------------
       Approach 3: Counting Sort Optimization
       Works efficiently when values are bounded (e.g. <= 100000)
       Time:  O(n + MAX_VAL)
       Space: O(MAX_VAL)
       ------------------------------------------------------------ */
    int minPairSum_counting(vector<int> nums) {
        const int MAXV = 100000;
        vector<int> freq(MAXV + 1, 0);

        for (int x : nums) freq[x]++;

        int l = 0, r = MAXV;
        int ans = 0;
        int pairs = nums.size() / 2;

        while (pairs--) {
            while (l <= MAXV && freq[l] == 0) l++;
            while (r >= 0 && freq[r] == 0) r--;

            ans = max(ans, l + r);

            freq[l]--;
            freq[r]--;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<int>> testCases = {
        {3, 5, 2, 3},
        {3, 5, 4, 2, 4, 6},
        {1, 1, 1, 1},
        {1, 2, 3, 4},
        {9, 2, 5, 1, 6, 3}
    };

    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int x : testCases[i]) cout << x << " ";
        cout << "\n";

        cout << "  Approach 1 (Sort):        "
             << sol.minPairSum_sort(testCases[i]) << "\n";
        cout << "  Approach 2 (TwoPointer):  "
             << sol.minPairSum_twoPointers(testCases[i]) << "\n";
        cout << "  Approach 3 (Counting):    "
             << sol.minPairSum_counting(testCases[i]) << "\n";
        cout << "--------------------------------------------------\n";
    }

    return 0;
}