#include <bits/stdc++.h>
using namespace std;
class Solution {
#define ll long long
public:
    // First method (Simulation-based approach)
    char kthCharacterSim(ll k, vector<int>& operations) {
        vector<int> dp = {0};
        for (int i : operations) {
            int dplen = dp.size();
            if (dplen > k) {
                break;
            } else if (i == 0) {
                for (int j = 0; j < dplen; j++) {
                    dp.push_back(dp[j]);
                }
            } else {
                for (int j = 0; j < dplen; j++) {
                    dp.push_back((dp[j] + 1) % 26);
                }
            }
        }
        return 'a' + dp[k - 1];
    }
    // Second method (Optimized bit-based reverse logic)
    char kthCharacterBitLogic(ll k, vector<int>& operations) {
        int Count = 0;
        ll val = k;
        while (val > 1) {
            int j = ceil(log2(val));
            val -= 1LL << (j - 1); // same as pow(2, j - 1) but faster
            Count += operations[j - 1];
        }
        return char('a' + (Count % 26));
    }
};
// --------- Testing both methods ---------
int main() {
    Solution sol;
    vector<tuple<long long, vector<int>>> testCases = {
        {1, {0, 1, 1}},              // Expected: 'a'
        {3, {0, 1, 1}},              // Expected: 'b'
        {5, {0, 0, 1, 1}},           // Example extended
        {7, {1, 0, 1}},              // Example with mixed
        {10, {1, 1, 0, 0, 1}},       // Larger case
        {100000, vector<int>(20, 1)} // Stress test with all increment ops
    };
    for (int i = 0; i < testCases.size(); ++i) {
        auto [k, ops] = testCases[i];
        cout << "Test Case " << i + 1 << ":\n";
        cout << "k = " << k << ", operations = { ";
        for (int op : ops) cout << op << " ";
        cout << "}\n";
        char result1 = sol.kthCharacterSim(k, ops);
        char result2 = sol.kthCharacterBitLogic(k, ops);
        cout << "Result (Simulation): " << result1 << "\n";
        cout << "Result (Bit Logic): " << result2 << "\n";
        cout << (result1 == result2 ? "✅ Match\n" : "❌ Mismatch\n");
        cout << "---------------------\n";
    }
    return 0;
}