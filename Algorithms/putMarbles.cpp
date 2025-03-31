#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if (k == 1) return 0;
        int n = weights.size();
        vector<int> subArr;
        // Compute the sum of adjacent pairs
        for (int i = 0; i < n - 1; i++) {
            subArr.push_back(weights[i] + weights[i + 1]);
        }
        // Sort the adjacent sums
        sort(subArr.begin(), subArr.end());
        // Use long long to prevent overflow during summation
        int i = k - 1;
        long long maxScore = accumulate(subArr.end() - i, subArr.end(), 0LL);
        long long minScore = accumulate(subArr.begin(), subArr.begin() + i, 0LL);
        return maxScore - minScore;
    }
};
int main() {
    Solution sol;
    // Test case 1: weights = [1, 3, 5, 1], k = 2
    vector<int> weights1 = {1, 3, 5, 1};
    int k1 = 2;
    cout << "Result for first test case: " << sol.putMarbles(weights1, k1) << endl;
    // Test case 2: weights = [1, 3], k = 2
    vector<int> weights2 = {1, 3};
    int k2 = 2;
    cout << "Result for second test case: " << sol.putMarbles(weights2, k2) << endl;
    return 0;
}