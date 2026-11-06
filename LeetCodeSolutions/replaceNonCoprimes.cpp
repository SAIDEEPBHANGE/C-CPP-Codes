#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    using ll = long long;
    // Euclidean algorithm for GCD
    ll GCD(ll a, ll b) {
        while (b != 0) {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    // Method 1: Brute-force style (reset loop on merge)
    vector<int> replaceNonCoprimesBrute(vector<int>& nums) {
        int i = 1;
        while (i < nums.size()) {
            int a = nums[i - 1];
            int b = nums[i];
            ll gcd = GCD(a, b);
            if (gcd > 1) {
                ll lcm = (1LL * a * b) / gcd;
                nums.erase(nums.begin() + i);
                nums[i - 1] = lcm;
                i = 1; // Restart from beginning
            } else {
                i++;
            }
        }
        return nums;
    }
    // Method 2: Stack-based (more efficient)
    vector<int> replaceNonCoprimesStack(vector<int>& nums) {
        vector<ll> stack;
        for (int num : nums) {
            ll curr = num;
            while (!stack.empty()) {
                ll top = stack.back();
                ll gcd = GCD(top, curr);
                if (gcd == 1)
                    break;
                curr = (top * curr) / gcd;
                stack.pop_back();
            }
            stack.push_back(curr);
        }
        vector<int> result;
        for (ll val : stack) {
            result.push_back(static_cast<int>(val));
        }
        return result;
    }
};
// Helper to print vector
void printVector(const vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}
// Test driver
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {6, 4, 3, 2, 7, 6, 2},
        {2, 2, 1, 1, 3, 3, 3},
        {1, 1, 1, 1},
        {15, 10, 3},
        {5, 10, 20},
        {2, 3, 5, 7, 11},
        {4, 6, 8, 9},
        {6, 9, 15},
        {2, 4, 8, 16}
    };
    cout << "Using Brute-force method:\n";
    for (auto test : testCases) {
        vector<int> result = sol.replaceNonCoprimesBrute(test);
        printVector(result);
    }
    cout << "\nUsing Stack-based method:\n";
    for (auto test : testCases) {
        vector<int> result = sol.replaceNonCoprimesStack(test);
        printVector(result);
    }
    return 0;
}
