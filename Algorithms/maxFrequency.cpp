#include <bits/stdc++.h>
using namespace std;

int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    unordered_map<int, int> freq;

    for (int num : nums) {
        freq[num]++;
    }

    int maxFreq = 0;

    // Try each unique value as a target
    for (auto& [target, count] : freq) {
        int opsUsed = 0;
        int tempFreq = count;

        // Try converting other numbers to 'target'
        for (auto& [num, cnt] : freq) {
            if (num == target) continue;
            int diff = abs(num - target);
            if (diff <= k && opsUsed < numOperations) {
                int canUse = min(cnt, numOperations - opsUsed);
                opsUsed += canUse;
                tempFreq += canUse;
            }
        }

        maxFreq = max(maxFreq, tempFreq);
    }

    return maxFreq;
}

int main() {
    // Test input
    vector<int> nums = {2, 70, 73};
    int k = 39;
    int numOperations = 2;

    cout << "Output: " << maxFrequency(nums, k, numOperations) << endl;
    return 0;
}
