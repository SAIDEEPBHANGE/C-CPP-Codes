#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*------------------------------------------------------------
     Approach 1: Single-pass Greedy (State-based)
     Time: O(n), Space: O(1)
    ------------------------------------------------------------*/
    bool isTrionicGreedy(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        int i = 0;
        // 1) strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;
        // 2) strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == n - 1) return false;
        // 3) strictly increasing again
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        return i == n - 1;
    }
    /*------------------------------------------------------------
     Approach 2: Explicit p, q partition check
     Time: O(n^2) worst, Space: O(1)
     (Educational / brute-force validation)
    ------------------------------------------------------------*/
    bool isTrionicBruteforce(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        for (int p = 1; p < n - 2; p++) {
            for (int q = p + 1; q < n - 1; q++) {
                bool ok = true;
                // increasing [0..p]
                for (int i = 0; i < p; i++)
                    if (nums[i] >= nums[i + 1]) ok = false;
                // decreasing [p..q]
                for (int i = p; i < q; i++)
                    if (nums[i] <= nums[i + 1]) ok = false;
                // increasing [q..n-1]
                for (int i = q; i < n - 1; i++)
                    if (nums[i] >= nums[i + 1]) ok = false;
                if (ok) return true;
            }
        }
        return false;
    }
    /*------------------------------------------------------------
     Approach 3: Precomputed monotonic arrays
     Time: O(n), Space: O(n)
    ------------------------------------------------------------*/
    bool isTrionicDP(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;
        vector<bool> inc(n, false), dec(n, false);
        // inc[i]: nums[0..i] strictly increasing
        inc[0] = true;
        for (int i = 1; i < n; i++)
            inc[i] = inc[i - 1] && (nums[i - 1] < nums[i]);
        // dec[i]: nums[i..n-1] strictly increasing
        dec[n - 1] = true;
        for (int i = n - 2; i >= 0; i--)
            dec[i] = dec[i + 1] && (nums[i] < nums[i + 1]);
        // check middle decreasing part
        for (int p = 1; p < n - 2; p++) {
            if (!inc[p]) continue;
            for (int q = p + 1; q < n - 1; q++) {
                bool ok = true;
                for (int i = p; i < q; i++)
                    if (nums[i] <= nums[i + 1]) ok = false;
                if (ok && dec[q]) return true;
            }
        }
        return false;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<vector<int>> testCases = {
        {1, 3, 5, 4, 2, 6, 8},
        {1, 2, 3, 4},
        {5, 4, 3, 2, 1},
        {1, 4, 2, 3},
        {1, 2, 5, 3, 1, 4, 6},
        {1, 3, 2, 1, 2}
    };
    for (int t = 0; t < (int)testCases.size(); t++) {
        vector<int> nums = testCases[t];
        cout << "Test Case " << t + 1 << ": ";
        for (int x : nums) cout << x << " ";
        cout << "\n";
        cout << "  Greedy      : " << sol.isTrionicGreedy(nums) << "\n";
        cout << "  Bruteforce  : " << sol.isTrionicBruteforce(nums) << "\n";
        cout << "  DP-based    : " << sol.isTrionicDP(nums) << "\n";
        cout << "-----------------------------------\n";
    }
    return 0;
}
