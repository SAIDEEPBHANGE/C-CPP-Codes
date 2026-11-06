#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for (int i = 2; i < n; i++) {
            if (arr[i] % 2 && arr[i - 1] % 2 && arr[i - 2] % 2) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    // Create a vector of test cases
    vector<vector<int>> test_cases = {
        {2, 4, 1, 3, 5},  // Expected output: true
        {1, 2, 3, 5, 7},  // Expected output: false
        {1, 3, 5, 7, 9},  // Expected output: true
        {10, 12, 14, 15, 17}, // Expected output: false
        {1, 3, 5, 7},      // Expected output: true
        {2, 4, 6, 8}       // Expected output: false
    };
    Solution sol;
    // Test all the test cases
    for (auto& test_case : test_cases) {
        bool result = sol.threeConsecutiveOdds(test_case);
        cout << "Test case: ";
        for (int num : test_case) {
            cout << num << " ";
        }
        cout << "\nResult: " << (result ? "True" : "False") << "\n\n";
    }
    return 0;
}