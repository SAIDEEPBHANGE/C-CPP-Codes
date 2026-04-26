#include <bits/stdc++.h>
using namespace std;
/*
    Problem: Find Kth Bit in Nth Binary String
    S1 = "0"
    Si = Si-1 + "1" + reverse(invert(Si-1))
    Goal: Return the kth bit in Sn.
*/
class Solution {
public:
    // ------------------------------------------------------------
    // Approach 1: Iterative Simulation (Optimal)
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // ------------------------------------------------------------
    char findKthBit_Iterative(int n, int k) {
        bool invert = false;
        while (n > 1) {
            int len = (1 << n) - 1;
            int mid = (len + 1) / 2;
            if (k == mid)
                return invert ? '0' : '1';
            if (k > mid) {
                k = len - k + 1;
                invert = !invert;
            }
            n--;
        }
        return invert ? '1' : '0';
    }
    // ------------------------------------------------------------
    // Approach 2: Recursive Divide & Conquer
    // Time Complexity: O(n)
    // Space Complexity: O(n) recursion stack
    // ------------------------------------------------------------
    char findKthBit_Recursive(int n, int k) {
        if (n == 1) return '0';
        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;
        if (k == mid) return '1';
        else if (k < mid)
            return findKthBit_Recursive(n - 1, k);
        else {
            char bit = findKthBit_Recursive(n - 1, len - k + 1);
            return (bit == '0') ? '1' : '0';
        }
    }
    // ------------------------------------------------------------
    // Approach 3: Construct Entire String (Brute Force)
    // Time Complexity: O(2^n)
    // Space Complexity: O(2^n)
    // ------------------------------------------------------------
    char findKthBit_Brute(int n, int k) {
        vector<string> arr;
        arr.push_back("0");
        for (int i = 1; i < n; i++) {
            string prev = arr.back();
            string inverted = prev;
            for (char &c : inverted)
                c = (c == '0') ? '1' : '0';
            reverse(inverted.begin(), inverted.end());
            string curr = prev + "1" + inverted;
            arr.push_back(curr);
        }
        return arr[n - 1][k - 1];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases: pair<n, k>
    vector<pair<int,int>> testCases = {
        {1, 1},
        {2, 3},
        {3, 1},
        {3, 5},
        {4, 11},
        {5, 16}
    };
    cout << "Comparing Different Approaches:\n\n";
    for (auto &test : testCases) {
        int n = test.first;
        int k = test.second;
        cout << "Input: n = " << n << ", k = " << k << "\n";
        char ans1 = sol.findKthBit_Iterative(n, k);
        char ans2 = sol.findKthBit_Recursive(n, k);
        char ans3 = sol.findKthBit_Brute(n, k);
        cout << "Iterative Approach : " << ans1 << "\n";
        cout << "Recursive Approach : " << ans2 << "\n";
        cout << "Brute Force        : " << ans3 << "\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}