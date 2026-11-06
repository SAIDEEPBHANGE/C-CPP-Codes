#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (string i : operations) {
            if (i[1] == '+') {
                X++;
            } else {
                X--;
            }
        }
        return X;
    }
};
int main() {
    // Test cases
    vector<vector<string>> testCases = {
        {"--X", "X++", "X++"},
        {"++X", "++X", "X++"},
        {"X++", "++X", "--X", "X--"}
    };
    Solution sol;
    for (auto& operations : testCases) {
        cout << "Operations: ";
        for (const string& op : operations) {
            cout << op << " ";
        }
        cout << "\nFinal value of X: " << sol.finalValueAfterOperations(operations) << endl;
    }
    return 0;
}
