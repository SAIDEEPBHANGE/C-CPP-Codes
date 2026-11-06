#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
        ---------------------------------------------------------
        Approach 1: Brute Force with Prime Check using sqrt(n)
        - For each number in range:
            - Count set bits using __builtin_popcount
            - Check if that count is prime using trial division
        Time Complexity: O(N * sqrt(32)) ≈ O(N)
        ---------------------------------------------------------
    */
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int approach1(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if (isPrime(setBits)) {
                ans++;
            }
        }
        return ans;
    }
    /*
        ---------------------------------------------------------
        Approach 2: Brian Kernighan’s Algorithm + Precomputed Primes
        - Count set bits using n = n & (n - 1)
        - Check if count exists in a predefined prime list
        Time Complexity: O(N)
        ---------------------------------------------------------
    */
    int countSetBits(int n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
    int approach2(int left, int right) {
        int result = 0;
        unordered_set<int> primeSet = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        for (int i = left; i <= right; i++) {
            int cnt = countSetBits(i);
            if (primeSet.count(cnt)) {
                result++;
            }
        }
        return result;
    }
    /*
        ---------------------------------------------------------
        Approach 3: Bitmask Trick for Prime Checking
        - Since maximum set bits for int (32-bit) is 32
        - Precompute prime bitmask
        - If (primeMask >> setBits) & 1 → prime
        Time Complexity: O(N)
        ---------------------------------------------------------
    */
    int approach3(int left, int right) {
        int result = 0;
        // Bitmask representing primes up to 31
        // Bits set at prime indices: 2,3,5,7,11,13,17,19,23,29,31
        int primeMask = 0;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        for (int p : primes) {
            primeMask |= (1 << p);
        }
        for (int i = left; i <= right; i++) {
            int setBits = __builtin_popcount(i);
            if ((primeMask >> setBits) & 1) {
                result++;
            }
        }
        return result;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases: {left, right}
    vector<pair<int, int>> testCases = {
        {6, 10},
        {10, 15},
        {1, 20},
        {842, 888},
        {1000, 1100}
    };
    for (size_t i = 0; i < testCases.size(); i++) {
        int left = testCases[i].first;
        int right = testCases[i].second;
        cout << "Test Case " << i + 1 << " (Range: " 
             << left << " to " << right << ")\n";
        int res1 = sol.approach1(left, right);
        int res2 = sol.approach2(left, right);
        int res3 = sol.approach3(left, right);
        cout << "Approach 1 (Prime Check with sqrt): " << res1 << "\n";
        cout << "Approach 2 (Kernighan + Prime Set): " << res2 << "\n";
        cout << "Approach 3 (Bitmask Optimization): " << res3 << "\n";
        cout << "----------------------------------------\n";
    }
    return 0;
}