#include <bits/stdc++.h>
using namespace std;

// Function to compute the maximum total damage
int maxTotalDamage(vector<int>& power) {
    unordered_map<int, long long> damageMap;

    // Sum total damage per unique spell damage value
    for (int dmg : power) {
        damageMap[dmg] += dmg;
    }

    // Extract and sort unique damage values
    vector<int> uniqueDamage;
    for (auto& pair : damageMap) {
        uniqueDamage.push_back(pair.first);
    }
    sort(uniqueDamage.begin(), uniqueDamage.end());

    int n = uniqueDamage.size();
    vector<long long> dp(n, 0);

    for (int i = 0; i < n; ++i) {
        long long include = damageMap[uniqueDamage[i]];
        int j = i - 1;

        // Skip all conflicting values: within [x-2, x+2]
        while (j >= 0 && uniqueDamage[j] >= uniqueDamage[i] - 2) {
            --j;
        }

        if (j >= 0) {
            include += dp[j];
        }

        long long exclude = (i > 0) ? dp[i - 1] : 0;
        dp[i] = max(include, exclude);
    }

    return dp[n - 1];
}

// Test cases
int main() {
    vector<vector<int>> testCases = {
        {2, 2, 3, 3, 3, 4},          // Expected output: 9 (3+3+3)
        {1, 2, 3, 4, 5},             // Expected output: 6 (1+3+5 or 2+4)
        {8, 10, 12, 10, 10, 8, 12},  // Expected output: 50 (10+10+10+12+8)
        {1, 1, 1, 1},                // Expected output: 4
        {5, 7, 9, 11, 13},           // Expected output: 45 (no values conflict)
        {3, 5, 7, 5, 3, 7, 9},       // Expected output: 21 (3+3+5+5+5 or 5+5+7+7 or similar)
        {},                          // Edge case: empty input → Expected output: 0
        {100},                       // Single spell → Expected output: 100
        {1, 2, 3, 4, 6, 7, 8},       // Expected output: 14 (2+4+8 or 1+3+6)
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        int result = maxTotalDamage(testCases[i]);
        cout << result << endl;
    }

    return 0;
}
