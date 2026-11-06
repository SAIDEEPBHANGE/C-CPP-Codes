#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Optimized iterative solution (Fibonacci approach)
    int climbStairsIterative(int n) {
        int a = 1;
        int b = 1;
        n -= 1;
        while (n > 0) {
            int temp = a + b;
            a = b;
            b = temp;
            n--;
        }
        return b;
    }
    // Dynamic programming solution with vector
    int climbStairsDP(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {0, 1, 2, 3, 5, 10, 20, 30};
    cout << "Testing climbStairs (Iterative and DP) Solutions:\n\n";
    for (int n : testCases) {
        int resultIter = sol.climbStairsIterative(n);
        int resultDP = sol.climbStairsDP(n);
        cout << "n = " << n << " | Iterative: " << resultIter << " | DP: " << resultDP << '\n';
        assert(resultIter == resultDP); // Ensures both solutions give the same result
    }
    cout << "\nAll test cases passed successfully!\n";
    return 0;
}