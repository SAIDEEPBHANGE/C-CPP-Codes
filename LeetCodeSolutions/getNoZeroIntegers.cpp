#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool CheckZero(int i) {
        string str = to_string(i);
        return str.find('0') != string::npos;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> Result;
        for (int i = 1; i < n; i++) {
            if (!CheckZero(i) && !CheckZero(n - i)) {
                Result.push_back(i);
                Result.push_back(n - i);
                break;
            }
        }
        return Result;
    }
};
// Test function
void runTests() {
    Solution sol;
    vector<int> testCases = {2, 11, 100, 101, 69, 2000};
    for (int n : testCases) {
        vector<int> result = sol.getNoZeroIntegers(n);
        cout << "n = " << n << " => ";
        if (!result.empty()) {
            cout << "[" << result[0] << ", " << result[1] << "]\n";
        } else {
            cout << "No valid pair found.\n";
        }
    }
}
int main() {
    runTests();
    return 0;
}
