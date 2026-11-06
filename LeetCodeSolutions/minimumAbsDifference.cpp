#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Using unordered_map (Original / Less Optimized)
    // ------------------------------------------------------------
    vector<vector<int>> minimumAbsDifference_Map(vector<int> arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, vector<vector<int>>> diffMap;
        int minDiff = INT_MAX;
        for (int i = 1; i < (int)arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            minDiff = min(minDiff, diff);
            diffMap[diff].push_back({arr[i - 1], arr[i]});
        }
        return diffMap[minDiff];
    }
    // ------------------------------------------------------------
    // Approach 2: Optimized Single Pass (Recommended)
    // ------------------------------------------------------------
    vector<vector<int>> minimumAbsDifference_Optimized(vector<int> arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int minDiff = INT_MAX;
        for (int i = 1; i < (int)arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result.clear();
                result.push_back({arr[i - 1], arr[i]});
            } else if (diff == minDiff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
// Utility function to print result
void printResult(const vector<vector<int>>& res) {
    cout << "[ ";
    for (const auto& p : res) {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
    cout << "]\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {4, 2, 1, 3},
        {1, 3, 6, 10, 15},
        {3, 8, -10, 23, 19, -4, -14, 27}
    };
    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int x : testCases[i]) cout << x << " ";
        cout << "\n";
        cout << "Approach 1 (Map-based): ";
        printResult(sol.minimumAbsDifference_Map(testCases[i]));
        cout << "Approach 2 (Optimized): ";
        printResult(sol.minimumAbsDifference_Optimized(testCases[i]));
        cout << "-----------------------------------\n";
    }
    return 0;
}
