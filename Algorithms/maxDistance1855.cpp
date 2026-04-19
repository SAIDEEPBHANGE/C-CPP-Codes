#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Two Pointer (Optimized - O(n + m))
    int maxDistanceTwoPointer(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, l2 = 0;
        int n = nums1.size(), m = nums2.size();
        int maxDist = 0;

        while (l1 < n && l2 < m) {
            if (nums1[l1] <= nums2[l2]) {
                maxDist = max(maxDist, l2 - l1);
                l2++;
            } else {
                l1++;
            }
        }
        return maxDist;
    }

    // Approach 2: Binary Search for each element (O(n log m))
    int maxDistanceBinarySearch(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int maxDist = 0;

        for (int i = 0; i < n; i++) {
            int left = i, right = m - 1, best = i - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums2[mid] >= nums1[i]) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (best >= i)
                maxDist = max(maxDist, best - i);
        }
        return maxDist;
    }

    // Approach 3: Brute Force (O(n * m)) - for completeness
    int maxDistanceBrute(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int maxDist = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < m; j++) {
                if (nums1[i] <= nums2[j]) {
                    maxDist = max(maxDist, j - i);
                }
            }
        }
        return maxDist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{55,30,5,4,2}, {100,20,10,10,5}},
        {{2,2,2}, {10,10,1}},
        {{30,29,19,5}, {25,25,25,25,25}},
        {{5,4}, {3,2}}
    };

    int testNum = 1;

    for (auto &test : testCases) {
        vector<int> nums1 = test.first;
        vector<int> nums2 = test.second;

        cout << "Test Case " << testNum++ << ":\n";

        int res1 = sol.maxDistanceTwoPointer(nums1, nums2);
        int res2 = sol.maxDistanceBinarySearch(nums1, nums2);
        int res3 = sol.maxDistanceBrute(nums1, nums2);

        cout << "Two Pointer Result      : " << res1 << "\n";
        cout << "Binary Search Result    : " << res2 << "\n";
        cout << "Brute Force Result      : " << res3 << "\n";
        cout << "-----------------------------------\n";
    }

    return 0;
}