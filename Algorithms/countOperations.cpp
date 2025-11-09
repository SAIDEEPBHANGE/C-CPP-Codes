#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        int a = max(num1, num2);
        int b = min(num1, num2);
        while (a && b) {
            cnt += a / b;
            a %= b;
            swap(a, b);
        }
        return cnt;
    }

    // Alternative version (simpler but slower)
    /*
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0)
            return 0;
        int cnt = 1;
        while ((num1 - num2) != 0) {
            if (num1 >= num2)
                num1 = num1 - num2;
            else
                num2 = num2 - num1;
            ++cnt;
        }
        return cnt;
    }
    */
};

int main() {
    Solution sol;
    
    // Vector of test cases
    vector<pair<int, int>> testCases = {
        {2, 3},
        {10, 10},
        {10, 0},
        {0, 5},
        {25, 5},
        {18, 12},
        {100, 1}
    };
    
    cout << "Testing countOperations:\n";
    for (auto &[num1, num2] : testCases) {
        cout << "countOperations(" << num1 << ", " << num2 << ") = "
             << sol.countOperations(num1, num2) << "\n";
    }
    
    return 0;
}
