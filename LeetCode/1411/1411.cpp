#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static const int MOD = 1e9 + 7;
    // ------------------------------------------------------------
    // Approach 1: Optimized DP (O(n) time, O(1) space)
    // ------------------------------------------------------------
    int numOfWays_OptimizedDP(int n) {
        long long A = 6; // Type A: all three colors different
        long long B = 6; // Type B: first and third same
        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;
            long long newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }
        return (A + B) % MOD;
    }
    // ------------------------------------------------------------
    // Approach 2: DP with arrays (O(n) time, O(n) space)
    // ------------------------------------------------------------
    int numOfWays_FullDP(int n) {
        vector<long long> A(n + 1), B(n + 1);
        A[1] = 6;
        B[1] = 6;
        for (int i = 2; i <= n; i++) {
            A[i] = (2 * A[i - 1] + 2 * B[i - 1]) % MOD;
            B[i] = (2 * A[i - 1] + 3 * B[i - 1]) % MOD;
        }
        return (A[n] + B[n]) % MOD;
    }
    // ------------------------------------------------------------
    // Approach 3: Matrix Exponentiation (O(log n) time)
    // ------------------------------------------------------------
    using Matrix = array<array<long long, 2>, 2>;
    Matrix multiply(const Matrix &a, const Matrix &b) {
        Matrix res{};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }
    Matrix matrixPower(Matrix base, int exp) {
        Matrix result = {{{1, 0}, {0, 1}}}; // Identity matrix
        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }
    int numOfWays_MatrixExpo(int n) {
        if (n == 1) return 12;
        // Transition matrix:
        // [A'] = [2 2] [A]
        // [B']   [2 3] [B]
        Matrix T = {{{2, 2}, {2, 3}}};
        Matrix Tn = matrixPower(T, n - 1);
        long long A1 = 6, B1 = 6;
        long long An = (Tn[0][0] * A1 + Tn[0][1] * B1) % MOD;
        long long Bn = (Tn[1][0] * A1 + Tn[1][1] * B1) % MOD;
        return (An + Bn) % MOD;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> testCases = {1, 2, 3, 5, 10, 1000};
    cout << "Number of Ways to Paint N x 3 Grid\n";
    cout << "---------------------------------\n";
    for (int n : testCases) {
        cout << "n = " << n << "\n";
        cout << "  Optimized DP      : " << sol.numOfWays_OptimizedDP(n) << "\n";
        cout << "  Full DP           : " << sol.numOfWays_FullDP(n) << "\n";
        cout << "  Matrix Exponent   : " << sol.numOfWays_MatrixExpo(n) << "\n";
        cout << "\n";
    }
    return 0;
}
