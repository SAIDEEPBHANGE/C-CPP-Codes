#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // ---------- Approach 1: Convert digits to number (not safe for very large inputs) ----------
    long long getNum(const vector<int>& digits, long long sum, int i) {
        if (i == (int)digits.size()) {
            return sum + 1;
        }
        sum = sum * 10 + digits[i];
        return getNum(digits, sum, i + 1);
    }

    vector<int> numToVec(long long num) {
        if (num == 0) return {0};
        vector<int> result;
        while (num > 0) {
            result.push_back(num % 10);
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }

public:
    vector<int> plusOne_Approach1(vector<int> digits) {
        long long num = getNum(digits, 0, 0);
        return numToVec(num);
    }

    // ---------- Approach 2: Simulate addition with carry ----------
    vector<int> plusOne_Approach2(vector<int> digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }

    // ---------- Approach 3: Optimized carry handling ----------
    vector<int> plusOne_Approach3(vector<int> digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

// Utility function to print vector
void printVector(const vector<int>& v) {
    cout << "[ ";
    for (int x : v) cout << x << " ";
    cout << "]";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<int>> testCases = {
        {1, 2, 3},
        {4, 3, 2, 1},
        {9},
        {9, 9, 9},
        {0}
    };

    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        printVector(testCases[i]);
        cout << "\n";

        cout << "  Approach 1: ";
        printVector(sol.plusOne_Approach1(testCases[i]));
        cout << "\n";

        cout << "  Approach 2: ";
        printVector(sol.plusOne_Approach2(testCases[i]));
        cout << "\n";

        cout << "  Approach 3: ";
        printVector(sol.plusOne_Approach3(testCases[i]));
        cout << "\n";

        cout << "---------------------------------\n";
    }

    return 0;
}
