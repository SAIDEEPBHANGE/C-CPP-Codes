#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> Result;
        for (int i : spells) {
            long long spell = i;
            // Ceiling division to get minimum potion needed
            long long threshold = (success + spell - 1) / spell;
            // Binary search to find the first potion >= threshold
            int low = 0, high = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (potions[mid] < threshold) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            Result.push_back(n - low);  // Count of valid potions
        }
        return Result;
    }
};
// Helper function to print vectors
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    Solution sol;
    // Test Case 1
    vector<int> spells1 = {10, 20, 30};
    vector<int> potions1 = {1, 2, 3, 4, 5};
    long long success1 = 100;
    vector<int> result1 = sol.successfulPairs(spells1, potions1, success1);
    cout << "Test Case 1 Output: ";
    printVector(result1);  // Expected: [0, 1, 3]
    // Test Case 2
    vector<int> spells2 = {5, 1, 3};
    vector<int> potions2 = {1, 2, 3, 4, 5};
    long long success2 = 7;
    vector<int> result2 = sol.successfulPairs(spells2, potions2, success2);
    cout << "Test Case 2 Output: ";
    printVector(result2);  // Expected: [4, 0, 3]
    // Test Case 3
    vector<int> spells3 = {15, 8, 18};
    vector<int> potions3 = {2, 3, 7, 11};
    long long success3 = 100;
    vector<int> result3 = sol.successfulPairs(spells3, potions3, success3);
    cout << "Test Case 3 Output: ";
    printVector(result3);  // Expected: [2, 0, 3]
    return 0;
}
