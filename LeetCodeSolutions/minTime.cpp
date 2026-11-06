#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finishTime(n, 0);
        for (int j = 0; j < m; ++j) {
            finishTime[0] += 1LL * mana[j] * skill[0];
            // Calculate the finish time for each skill level
            for (int i = 1; i < n; ++i)
                finishTime[i] = max(finishTime[i], finishTime[i - 1]) +
                                1LL * mana[j] * skill[i];
            // Adjust finish times backward
            for (int i = n - 1; i > 0; --i)
                finishTime[i - 1] = finishTime[i] - 1LL * mana[j] * skill[i];
        }
        return finishTime[n - 1];
    }
};
int main() {
    Solution sol;
    // Test case 1
    vector<int> skill1 = {1, 2, 3};
    vector<int> mana1 = {10, 20};
    cout << "Test Case 1: " << sol.minTime(skill1, mana1) << endl; // Expected output: (some value)
    // Test case 2
    vector<int> skill2 = {5, 10, 15};
    vector<int> mana2 = {2, 4, 6};
    cout << "Test Case 2: " << sol.minTime(skill2, mana2) << endl; // Expected output: (some value)
    // Test case 3 (Edge case with single skill and mana values)
    vector<int> skill3 = {1};
    vector<int> mana3 = {10};
    cout << "Test Case 3: " << sol.minTime(skill3, mana3) << endl; // Expected output: (some value)
    return 0;
}
