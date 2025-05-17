#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int SumOfDigit(int i) {
        int sum = 0;
        while (i > 0) {
            sum += i % 10;
            i /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> ump;
        int maxSum = -1;
        for (int i : nums) {
            int CurrSum = SumOfDigit(i);
            if (ump.count(CurrSum)) {
                maxSum = max(maxSum, i + ump[CurrSum]);
                ump[CurrSum] = max(ump[CurrSum], i);
            } else {
                ump[CurrSum] = i;
            }
        }
        return maxSum;
    }
};
int main() {
    // List of test cases
    vector<vector<int>> testCases = {
        {18, 43, 36, 13, 7},
        {10, 12, 19, 14},
        {1, 2, 3, 4},
        {51, 42, 33, 24, 15},
        {111, 222, 123, 321}
    };
    Solution sol;
    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": ";
        int result = sol.maximumSum(testCases[i]);
        cout << result << endl;
    }
    return 0;
}