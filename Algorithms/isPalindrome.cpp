#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string baseK) {
        int i = 0, j = baseK.size() - 1;
        while (i <= j) {
            if (baseK[i] != baseK[j]) return false;
            i++, j--;
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
        return res; // note: reversed, but palindrome check still works
    }
    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1;
        while (n > 0) {
            int half_length = (L + 1) / 2;
            long long min_num = pow(10LL, half_length - 1);
            long long max_num = pow(10LL, half_length) - 1;
            for (long long num = min_num; num <= max_num; num++) {
                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(), second_half.end());
                string pal = (L % 2 == 0)
                           ? first_half + second_half
                           : first_half + second_half.substr(1);
                long long pal_num = stoll(pal);
                string baseK = convertToBaseK(pal_num, k);
                if (isPalindrome(baseK)) {
                    sum += pal_num;
                    n--;
                    if (n == 0) break;
                }
            }
            L++;
        }
        return sum;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int>> tests = {
        {2, 5},
        {3, 7},
        {7, 3}
    };
    Solution sol;
    for (auto &tc : tests) {
        int k = tc.first, n = tc.second;
        cout << "k = " << k << ", n = " << n 
             << "  =>  sum = " << sol.kMirror(k, n) << "\n";
    }
    return 0;
}