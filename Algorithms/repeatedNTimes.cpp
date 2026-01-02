#include <bits/stdc++.h>
using namespace std;

/*
 LeetCode: N-Repeated Element in Size 2N Array

 We provide multiple approaches inside a single Solution class
 and compare their outputs on hardcoded test cases.
*/

class Solution {
public:
    // Approach 1: Frequency map (O(n) time, O(n) space)
    int repeatedNTimes_freqMap(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size() / 2;
        for (int x : nums) {
            freq[x]++;
            if (freq[x] == n) return x;
        }
        return -1; // fallback
    }

    // Approach 2: Neighbor comparison trick (O(n) time, O(1) space)
    int repeatedNTimes_neighborCheck(vector<int>& nums) {
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] == nums[i + 1]) return nums[i];
            if (i + 2 < (int)nums.size() && nums[i] == nums[i + 2]) return nums[i];
            if (i + 3 < (int)nums.size() && nums[i] == nums[i + 3]) return nums[i];
        }
        return -1;
    }

    // Approach 3: Using a set to detect first repeat (O(n) time, O(n) space)
    int repeatedNTimes_set(vector<int>& nums) {
        unordered_set<int> seen;
        for (int x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 3},
        {2, 1, 2, 5, 3, 2},
        {5, 1, 5, 2, 5, 3, 5, 4},
        {9, 7, 8, 9, 6, 9, 5, 9}
    };

    // Run all approaches on each test case
    for (int i = 0; i < (int)testCases.size(); i++) {
        vector<int> nums = testCases[i];

        cout << "Test Case " << i + 1 << ": ";
        for (int x : nums) cout << x << " ";
        cout << "\n";

        cout << "  Frequency Map Approach: "
             << sol.repeatedNTimes_freqMap(nums) << "\n";

        cout << "  Neighbor Check Approach: "
             << sol.repeatedNTimes_neighborCheck(nums) << "\n";

        cout << "  Set-Based Approach: "
             << sol.repeatedNTimes_set(nums) << "\n";

        cout << "-----------------------------------\n";
    }

    return 0;
}
