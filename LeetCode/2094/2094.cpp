#include <bits/stdc++.h>
using namespace std;
struct test_case {
    vector<int> digits;
    string description;
};
class Solution {
public:
    // Version 1: Basic brute-force with vector and erase
    vector<int> method1(vector<int> digits) {
        vector<int> result;
        for (int i = 100; i < 1000; i++) {
            if (i % 2 != 0) continue;
            vector<int> tempDigits = digits;
            int temp = i;
            bool isValid = true;
            for (int j = 0; j < 3; j++) {
                int lastDigit = temp % 10;
                auto it = find(tempDigits.begin(), tempDigits.end(), lastDigit);
                if (it != tempDigits.end()) {
                    tempDigits.erase(it);
                } else {
                    isValid = false;
                    break;
                }
                temp /= 10;
            }
            if (isValid) {
                result.push_back(i);
            }
        }
        return result;
    }
    // Version 2: Brute-force with set to ensure uniqueness
    vector<int> method2(vector<int> digits) {
        set<int> uniqueResults;
        for (int i = 100; i < 1000; i++) {
            if (i % 2 != 0) continue;
            vector<int> tempDigits = digits;
            int temp = i;
            bool isValid = true;
            for (int j = 0; j < 3; j++) {
                int lastDigit = temp % 10;
                auto it = find(tempDigits.begin(), tempDigits.end(), lastDigit);
                if (it != tempDigits.end()) {
                    tempDigits.erase(it);
                } else {
                    isValid = false;
                    break;
                }
                temp /= 10;
            }
            if (isValid) {
                uniqueResults.insert(i);
            }
        }
        return vector<int>(uniqueResults.begin(), uniqueResults.end());
    }
    // Version 3: Optimized recursive backtracking with set
    void solveRecursive(int cur, int k, vector<int>& freq, set<int>& res) {
        if (k == 0) {
            if (cur % 2 == 0)
                res.insert(cur);
            return;
        }
        cur *= 10;
        for (int i = 0; i <= 9; ++i) {
            if (cur == 0 && i == 0) continue;
            if (freq[i] > 0) {
                freq[i]--;
                solveRecursive(cur + i, k - 1, freq, res);
                freq[i]++;
            }
        }
    }
    vector<int> method3(vector<int> digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;
        set<int> res;
        solveRecursive(0, 3, freq, res);
        return vector<int>(res.begin(), res.end());
    }
    // Version 4: Frequency-based checking without recursion
    vector<int> method4(vector<int> digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;
        set<int> res;
        for (int i = 100; i <= 999; ++i) {
            if (i % 2 != 0) continue;
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;
            vector<int> need(10, 0);
            need[a]++; need[b]++; need[c]++;
            bool valid = true;
            for (int d = 0; d < 10; ++d) {
                if (need[d] > freq[d]) {
                    valid = false;
                    break;
                }
            }
            if (valid) res.insert(i);
        }
        return vector<int>(res.begin(), res.end());
    }
    // Helper to print result
    void printVector(const vector<int>& v) {
        for (int i : v) cout << i << " ";
        cout << endl;
    }
    // Run all four methods
    void runTestCases(const vector<test_case>& tests) {
        for (const auto& t : tests) {
            cout << "Test: " << t.description << endl;
            cout << "Input digits: ";
            printVector(t.digits);
            cout << "Method 1: ";
            printVector(method1(t.digits));
            cout << "Method 2: ";
            printVector(method2(t.digits));
            cout << "Method 3: ";
            printVector(method3(t.digits));
            cout << "Method 4: ";
            printVector(method4(t.digits));
            cout << "------------------------" << endl;
        }
    }
};
int main() {
    vector<test_case> tests = {
        {{2, 1, 3, 0}, "Basic digits"},
        {{1, 1, 2, 0}, "Duplicates"},
        {{0, 0, 0, 8}, "Zeros with even"},
        {{5, 7, 9}, "No even digit"},
        {{1, 2, 3, 4, 5}, "All unique digits"}
    };
    Solution sol;
    sol.runTestCases(tests);
    return 0;
}