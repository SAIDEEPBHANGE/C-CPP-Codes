#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int MaxFreq = 1;
        unordered_map<int, int> freq;
        // Calculate frequency of each element
        for (int i : nums) {
            freq[i]++;
            MaxFreq = max(MaxFreq, freq[i]);
        }
        // Find the sum of elements that have the maximum frequency
        int result = 0;
        for (auto i : freq) {
            if (i.second == MaxFreq) {
                result += i.first;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    // Test cases
    vector<vector<int>> testCases = {
        {1, 2, 2, 3, 3, 3},    // Example test case
        {4, 4, 4, 5, 5, 6},    // Test case with different frequencies
        {7, 8, 9, 9, 9, 8, 7}, // Test case with multiple frequent elements
        {10, 10, 10, 10, 5},   // Test case with one element being the most frequent
        {1, 2, 3, 4, 5}        // Test case with no duplicates
    };
    for (const auto& testCase : testCases) {
        int result = sol.maxFrequencyElements(testCase);
        cout << "For input: ";
        for (int num : testCase) {
            cout << num << " ";
        }
        cout << "\nMax frequency sum: " << result << endl;
    }
    return 0;
}
