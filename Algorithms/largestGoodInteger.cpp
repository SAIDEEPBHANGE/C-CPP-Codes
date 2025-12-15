#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Method 1: Optimized version (string comparison)
    string largestGoodIntegerOptimized(string num) {
        string res = "";
        for (int i = 0; i <= num.size() - 3; i++) {
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2]) {
                string curr = num.substr(i, 3);
                if (curr > res) {
                    res = curr;
                }
            }
        }
        return res;
    }
    // Method 2: Original version (integer comparison with skip)
    string largestGoodIntegerOriginal(string num) {
        int n = num.length() - 2;
        string str = "";
        int str_temp = -1;
        for (int i = 0; i < n; i++) {
            int temp = num[i] - '0';
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && str_temp < temp) {
                str_temp = temp;
                str = num.substr(i, 3);
                i += 2; // Skipping overlapping triplets (optional)
            }
        }
        return str;
    }
};
int main() {
    vector<string> testCases = {
        "6777133339",
        "2300019",
        "42352338",
        "0000000",
        "123456789",
        "999111000888",
        "222333444555666777888999"
    };
    Solution sol;
    cout << "Testing both versions:\n\n";
    for (const string& test : testCases) {
        cout << "Input: " << test << "\n";
        cout << "Optimized: " << sol.largestGoodIntegerOptimized(test) << "\n";
        cout << "Original : " << sol.largestGoodIntegerOriginal(test) << "\n";
        cout << "----------------------------------\n";
    }
    return 0;
}
