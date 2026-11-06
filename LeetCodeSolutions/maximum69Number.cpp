#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Recursive helper
    void fromStart(int num, int& res, bool& changed) {
        if (num == 0)
            return;
        fromStart(num / 10, res, changed);
        int digit = num % 10;
        if (!changed && digit == 6) {
            digit = 9;
            changed = true;
        }
        res = res * 10 + digit;
    }
public:
    // Recursive method
    int maximum69NumberRecursive(int num) {
        int result = 0;
        bool changed = false;
        fromStart(num, result, changed);
        return result;
    }
    // Iterative method
    int maximum69NumberIterative(int num) {
        string s = to_string(num);
        for (char& c : s) {
            if (c == '6') {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};
int main() {
    vector<int> testCases = {9669, 9996, 9999, 6969, 6699};
    Solution sol;
    cout << "Test Results:\n";
    for (int num : testCases) {
        int resultRecursive = sol.maximum69NumberRecursive(num);
        int resultIterative = sol.maximum69NumberIterative(num);
        cout << "Input: " << num << " | Recursive: " << resultRecursive
             << " | Iterative: " << resultIterative << "\n";
    }
    return 0;
}
