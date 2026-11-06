#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    double eps = 0.1;
    bool solve(vector<double>& c) {
        if (c.size() == 1)
            return abs(c[0] - 24) <= eps;
        for (int i = 0; i < c.size(); i++) {
            for (int j = 0; j < c.size(); j++) {
                if (i == j)
                    continue;
                vector<double> temp;
                for (int k = 0; k < c.size(); k++) {
                    if (k != i && k != j)
                        temp.push_back(c[k]);
                }
                double a = c[i];
                double b = c[j];
                vector<double> pos = {a + b, a - b, b - a, a * b};
                if (abs(b) > 1e-6)
                    pos.push_back(a / b);
                if (abs(a) > 1e-6)
                    pos.push_back(b / a);
                for (double p : pos) {
                    temp.push_back(p);
                    if (solve(temp))
                        return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> convertDouble;
        for (int i : cards) {
            convertDouble.push_back(1.0 * i);
        }
        return solve(convertDouble);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> testCases = {
        {4, 1, 8, 7},     // true
        {1, 2, 1, 2},     // false
        {3, 3, 8, 8},     // true
        {1, 5, 5, 5},     // true
        {1, 1, 1, 1},     // false
        {7, 7, 3, 3},     // true
    };
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": ";
        for (int num : testCases[i]) {
            cout << num << " ";
        }
        cout << "=> ";
        bool result = sol.judgePoint24(testCases[i]);
        cout << (result ? "true" : "false") << endl;
    }
    return 0;
}
