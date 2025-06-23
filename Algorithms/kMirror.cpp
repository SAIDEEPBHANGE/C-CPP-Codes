#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // ---------- Shared Helpers ----------
    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    string convertToBaseK(long long num, int k) {
        if (num == 0) return "0";
        string res = "";
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    // ---------- Version 1: Mirror from half ----------
    // Make a palindrome from half
    long long makePalindrome(int half, bool odd) {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (odd) rev = rev.substr(1); // remove middle digit if odd
        return stoll(s + rev);
    }
    long long kMirrorV1(int k, int n) {
        vector<long long> results;
        for (int parity = 0; parity <= 1; ++parity) {
            int curHalf = 1;
            while ((int)results.size() < n) {
                long long num = makePalindrome(curHalf, parity == 1);
                string baseK = convertToBaseK(num, k);
                if (isPalindrome(baseK)) {
                    results.push_back(num);
                }
                ++curHalf;
            }
            if ((int)results.size() >= n) break;
        }
        return accumulate(results.begin(), results.begin() + n, 0LL);
    }
    // ---------- Version 2: Palindrome by length ----------
    long long kMirrorV2(int k, int n) {
        long long sum = 0;
        int L = 1;
        while (n > 0) {
            int halfLength = (L + 1) / 2;
            long long start = pow(10, halfLength - 1);
            long long end = pow(10, halfLength) - 1;
            for (long long i = start; i <= end && n > 0; ++i) {
                string firstHalf = to_string(i);
                string secondHalf = firstHalf;
                reverse(secondHalf.begin(), secondHalf.end());
                string full = (L % 2 == 0) ? (firstHalf + secondHalf)
                                           : (firstHalf + secondHalf.substr(1));
                long long num = stoll(full);
                string baseK = convertToBaseK(num, k);
                if (isPalindrome(baseK)) {
                    sum += num;
                    n--;
                }
            }
            L++;
        }
        return sum;
    }
};
// ---------- Driver Code ----------
int main() {
    Solution sol;
    // Test cases: {k, n}
    vector<pair<int, int>> testCases = {
        {2, 5},
        {3, 7},
        {7, 17},
        {10, 1},
        {9, 9}
    };
    for (auto& [k, n] : testCases) {
        cout << "k = " << k << ", n = " << n << endl;
        cout << "  → V1 Sum of k-mirror numbers = " << sol.kMirrorV1(k, n) << endl;
        cout << "  → V2 Sum of k-mirror numbers = " << sol.kMirrorV2(k, n) << endl;
        cout << "-------------------------------------" << endl;
    }
    return 0;
}