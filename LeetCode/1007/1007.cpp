#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Optimized Solution 1: Using counts for each number (1-6)
    int minDominoRotations_v1(vector<int>& tops, vector<int>& bottoms) {
        vector<int> topsCount(7), bottomsCount(7), CommonIndexCount(7);
        int n = tops.size();
        // Counting occurrences of each number on top, bottom, and both
        for (int i = 0; i < n; i++) {
            int top = tops[i];
            int bottom = bottoms[i];
            topsCount[top]++;
            bottomsCount[bottom]++;
            if (top == bottom)
                CommonIndexCount[top]++;
        }
        // Checking for each possible number (1-6)
        for (int i = 1; i <= 6; i++) {
            if (topsCount[i] + bottomsCount[i] - CommonIndexCount[i] == n) {
                return min(n - topsCount[i], n - bottomsCount[i]);
            }
        }
        return -1; // No valid solution found
    }
    // Optimized Solution 2: Directly checking each number (1-6)
    int minDominoRotations_v2(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        // Checking for each number (1 through 6) as a possible candidate.
        for (int target = 1; target <= 6; target++) {
            int topRotations = 0, bottomRotations = 0;
            bool isValid = true;
            // Check each domino
            for (int i = 0; i < n; i++) {
                if (tops[i] != target && bottoms[i] != target) {
                    isValid = false;  // This number can't be made to match the target
                    break;
                }
                if (tops[i] != target) topRotations++;  // We would need to rotate the top
                if (bottoms[i] != target) bottomRotations++;  // We would need to rotate the bottom
            }
            if (isValid) {
                // Return the minimum rotations required for either all tops or bottoms
                return min(topRotations, bottomRotations);
            }
        }
        return -1;  // If no valid target is found
    }
};
int main() {
    // Vector of test cases
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{2, 1, 2, 4, 2, 2}, {5, 2, 6, 2, 3, 2}}, // Expected output: 2 (for Solution 1 and Solution 2)
        {{3, 5, 1, 2, 3}, {3, 6, 3, 3, 4}},       // Expected output: -1 (for both solutions)
        {{1, 2, 3, 4, 1}, {1, 1, 1, 1, 1}},       // Expected output: 0 (for Solution 1 and Solution 2)
    };
    Solution sol;
    // Running the test cases
    for (int i = 0; i < testCases.size(); i++) {
        auto& [tops, bottoms] = testCases[i];
        // Testing Solution 1
        int result1 = sol.minDominoRotations_v1(tops, bottoms);
        cout << "Test case " << i + 1 << " (Solution 1): " << result1 << endl;
        // Testing Solution 2
        int result2 = sol.minDominoRotations_v2(tops, bottoms);
        cout << "Test case " << i + 1 << " (Solution 2): " << result2 << endl;
        cout << "-------------------------------\n";
    }
    return 0;
}