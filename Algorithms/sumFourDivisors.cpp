#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*------------------------------------------------------------
     Approach 1: Brute Force Divisor Counting
     - For each number, iterate up to sqrt(n)
     - Count divisors and sum them
     - If exactly 4 divisors, add sum
    ------------------------------------------------------------*/
    int sumFourDivisors_bruteforce(const vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    cnt++;
                    sum += i;
                    if (i != num / i) {
                        cnt++;
                        sum += num / i;
                    }
                }
            }
            if (cnt == 4) result += sum;
        }
        return result;
    }

    /*------------------------------------------------------------
     Approach 2: Mathematical Optimization
     Observation:
     - A number has exactly 4 divisors if and only if:
       1) num = p^3 where p is prime
       2) num = p * q where p and q are distinct primes
    ------------------------------------------------------------*/
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors_math(const vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            // Case 1: p^3
            int p = round(cbrt(num));
            if ((long long)p * p * p == num && isPrime(p)) {
                // divisors: 1, p, p^2, p^3
                result += (1 + p + p * p + num);
                continue;
            }

            // Case 2: p * q
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    int j = num / i;
                    if (i != j && isPrime(i) && isPrime(j)) {
                        // divisors: 1, p, q, p*q
                        result += (1 + i + j + num);
                    }
                    break;
                }
            }
        }
        return result;
    }

    /*------------------------------------------------------------
     Approach 3: Brute Force with Memoization
     - Cache results for repeated numbers
     - Avoid recomputation
    ------------------------------------------------------------*/
    int sumFourDivisors_memo(const vector<int>& nums) {
        unordered_map<int, int> memo;
        int result = 0;

        for (int num : nums) {
            if (memo.count(num)) {
                if (memo[num] != -1) result += memo[num];
                continue;
            }

            int cnt = 0, sum = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    cnt++;
                    sum += i;
                    if (i != num / i) {
                        cnt++;
                        sum += num / i;
                    }
                }
            }

            if (cnt == 4) {
                memo[num] = sum;
                result += sum;
            } else {
                memo[num] = -1;
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {21, 4, 7},
        {8, 10, 14},
        {16, 9, 25},
        {21, 21, 8, 10}
    };

    for (size_t i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        for (int x : testCases[i]) cout << x << " ";
        cout << "\n";

        cout << "  Brute Force Result      : "
             << sol.sumFourDivisors_bruteforce(testCases[i]) << "\n";

        cout << "  Math Optimized Result   : "
             << sol.sumFourDivisors_math(testCases[i]) << "\n";

        cout << "  Memoized Result         : "
             << sol.sumFourDivisors_memo(testCases[i]) << "\n";

        cout << "----------------------------------------\n";
    }

    return 0;
}
