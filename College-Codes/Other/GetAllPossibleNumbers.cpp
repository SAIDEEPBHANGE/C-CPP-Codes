#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void GetAllPossibleNumbers(vector<int>& arr) {
        int n = arr.size();
        set<int> result; // Use set to avoid duplicates
        // Generate all possible lengths from 1 to n
        for (int len = 1; len <= n; ++len) {
            vector<bool> used(n, false);
            vector<int> current;
            generatePermutations(arr, used, current, result, len);
        }
        // Print all unique numbers
        for (int num : result) {
            cout << num << endl;
        }
    }
private:
    void generatePermutations(vector<int>& arr, vector<bool>& used, vector<int>& current,
                              set<int>& result, int targetLength) {
        if (current.size() == targetLength) {
            // Convert current digit list to number
            int num = 0;
            for (int d : current) {
                num = num * 10 + d;
            }
            result.insert(num);
            return;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (!used[i]) {
                used[i] = true;
                current.push_back(arr[i]);
                generatePermutations(arr, used, current, result, targetLength);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
int main() {
    vector<int> arr = {2, 1, 3, 0};
    Solution sol;
    sol.GetAllPossibleNumbers(arr);
    return 0;
}