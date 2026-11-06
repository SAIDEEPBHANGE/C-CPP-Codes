#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int Result = -1;
        unordered_map<int, int> ump;
        for (int i : arr) {
            ump[i]++;
        }
        for (auto [i, j] : ump) {
            if (i == j) {
                Result = max(Result, i);
            }
        }
        return Result;
    }
};
int main() {
    Solution sol;
    // Test Case 1
    vector<int> arr1 = {2, 2, 3, 4};
    cout << "Test Case 1 Result: " << sol.findLucky(arr1) << endl; // Output: 2
    // Test Case 2
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << "Test Case 2 Result: " << sol.findLucky(arr2) << endl; // Output: 3
    // Test Case 3
    vector<int> arr3 = {5};
    cout << "Test Case 3 Result: " << sol.findLucky(arr3) << endl; // Output: -1
    // Test Case 4
    vector<int> arr4 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Test Case 4 Result: " << sol.findLucky(arr4) << endl; // Output: 7
    // Test Case 5
    vector<int> arr5 = {1, 1, 2, 2, 2, 3, 3, 3, 3};
    cout << "Test Case 5 Result: " << sol.findLucky(arr5) << endl; // Output: -1
    return 0;
}