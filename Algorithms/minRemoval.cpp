#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Brute Force (O(n^2 log n))
    // Try every subarray after sorting and check validity
    // ------------------------------------------------------------
    int minRemovalBruteForce(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if ((long long)nums[j] <= (long long)nums[i] * k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return n - maxLen;
    }

    // ------------------------------------------------------------
    // Approach 2: Sliding Window / Two Pointers (O(n log n))
    // Optimal solution
    // ------------------------------------------------------------
    int minRemovalSlidingWindow(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, maxLen = 0;

        for (int j = 0; j < n; j++) {
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return n - maxLen;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4}, 2},
        {{4, 6, 2, 8}, 2},
        {{1, 3, 6, 10, 15}, 3},
        {{5, 5, 5, 5}, 1},
        {{1, 10, 100}, 10}
    };

    for (int idx = 0; idx < (int)testCases.size(); idx++) {
        vector<int> nums = testCases[idx].first;
        int k = testCases[idx].second;

        cout << "Test Case " << idx + 1 << ":\n";
        cout << "Array: ";
        for (int x : nums) cout << x << " ";
        cout << "\nK = " << k << "\n";

        cout << "Brute Force Result: "
             << sol.minRemovalBruteForce(nums, k) << "\n";

        cout << "Sliding Window Result: "
             << sol.minRemovalSlidingWindow(nums, k) << "\n";

        cout << "-----------------------------------\n";
    }

    return 0;
}
