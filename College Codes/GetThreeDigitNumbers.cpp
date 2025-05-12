#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void GetThreeDigitNumbers(vector<int>& arr) {
        int n = arr.size();
        set<int> result; // To avoid duplicates
        vector<bool> used(n, false);
        vector<int> current;
        generatePermutations(arr, used, current, result, 3);
        // Print all unique 3-digit numbers
        for (int num : result) {
            cout << num << endl;
        }
    }
private:
    void generatePermutations(vector<int>& arr, vector<bool>& used, vector<int>& current,
                              set<int>& result, int targetLength) {
        if (current.size() == targetLength) {
            if (current[0] == 0) return; // Skip numbers starting with 0
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
    sol.GetThreeDigitNumbers(arr);
    return 0;
}