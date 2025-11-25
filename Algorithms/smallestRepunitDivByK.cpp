#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Main function: smallest repunit divisible by k
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) 
            return -1;
        int remainder = 0;
        for (int length = 1; length <= k; length++) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) return length;
        }
        return -1;
    }
    // Helper method to run multiple test cases
    vector<int> runTests(const vector<int>& testcases) {
        vector<int> results;
        for (int k : testcases) {
            results.push_back(smallestRepunitDivByK(k));
        }
        return results;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    // Vector of test cases
    vector<int> testcases = {1, 2, 3, 7, 13, 17, 23, 37, 101};
    // Run all tests
    vector<int> results = sol.runTests(testcases);
    // Output results
    for (size_t i = 0; i < testcases.size(); i++) {
        cout << "k = " << testcases[i] 
             << "  ->  result = " << results[i] << "\n";
    }
    return 0;
}