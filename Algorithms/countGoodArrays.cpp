#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MX = 1e5;
long long fact[MX];
long long inv_fact[MX];
// Solution 1: Your initial solution (with recursive MakePower and recalculating factorials/inverses every time)
class Solution1 {
public:
    long long MakePower(long long a, long long b) {
        if (b == 0)
            return 1;
        long long half = MakePower(a, b / 2);
        long long Result = (half * half) % MOD;
        if (b % 2 == 1)
            Result = (Result * a) % MOD;
        return Result;
    }
    long long Combinations(int n, int k, vector<long long>& fn, vector<long long>& Ifn) {
        return fn[n] * Ifn[n - k] % MOD * Ifn[k] % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n + 1, 1);
        factorial[0] = 1;
        factorial[1] = 1;
        // Calculate n!
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
        // INVERSE FACTORIAL  Calculate (n)^MOD-2
        vector<long long> InverseFactorial(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            InverseFactorial[i] = MakePower(factorial[i], MOD - 2);
        }
        long long Result = Combinations(n - 1, k, factorial, InverseFactorial);
        Result = (m * Result) % MOD;
        Result = (Result * MakePower(m - 1, n - k - 1)) % MOD;
        return Result;
    }
};
// Solution 2: Optimized solution using precomputed factorials and inverse factorials
class Solution2 {
private:
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) return;
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);  // Using Fermat's Little Theorem
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init(); // Initialize factorials and inverse factorials
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
// Solution 3: A combined version of your and my code using efficient combination and fast exponentiation
class Solution3 {
private:
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) return; // To avoid recomputing
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);  // Using Fermat's Little Theorem
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }
public:
    int countGoodArrays(int n, int m, int k) {
        init(); // Initialize factorials and inverse factorials
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
int main() {
    // Vector of test cases, each test case has n, m, and k
    vector<tuple<int, int, int>> test_cases = {
        {5, 3, 2},   // Test Case 1
        {10, 7, 3},  // Test Case 2
        {100, 10, 5}, // Test Case 3
        {1000, 100, 50} // Test Case 4
    };
    Solution1 sol1;
    Solution2 sol2;
    Solution3 sol3;
    // Process each test case for all 3 solutions
    for (auto& test_case : test_cases) {
        int n, m, k;
        tie(n, m, k) = test_case;
        cout << "For n = " << n << ", m = " << m << ", k = " << k << endl;
        // Solution 1 (your original approach)
        cout << "Solution 1 Result: " << sol1.countGoodArrays(n, m, k) << endl;
        // Solution 2 (optimized with precomputed factorials)
        cout << "Solution 2 Result: " << sol2.countGoodArrays(n, m, k) << endl;
        // Solution 3 (combined version)
        cout << "Solution 3 Result: " << sol3.countGoodArrays(n, m, k) << endl;
        cout << "---------------------------------" << endl;
    }
    return 0;
}