#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> Result;
        for (int i = 1; i <= n / 2; ++i) {
            Result.push_back(i);
            Result.push_back(-i);
        }
        if (n % 2 != 0) {
            Result.push_back(0);
        }
        return Result;
    }
};
// Utility function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "]";
}
int main() {
    Solution sol;
    // Test cases
    vector<int> testCases = {1, 2, 3, 4, 5, 10};
    for (int n : testCases) {
        vector<int> result = sol.sumZero(n);
        cout << "n = " << n << " --> ";
        printVector(result);
        // Optional: verify sum == 0
        int sum = accumulate(result.begin(), result.end(), 0);
        cout << " | Sum = " << sum << endl;
    }
    return 0;
}
