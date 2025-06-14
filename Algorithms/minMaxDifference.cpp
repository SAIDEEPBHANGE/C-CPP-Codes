#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMaxDifference(int num) {
        string MaxString = to_string(num);
        string MinString = MaxString;
        // Find first digit that's not '9' for max replacement
        int Idx = MaxString.find_first_not_of('9');
        if (Idx != string::npos) {
            char nine = MaxString[Idx];
            replace(begin(MaxString), end(MaxString), nine, '9');
        }
        // Replace first digit in MinString with '0'
        char zero = MinString[0];
        replace(begin(MinString), end(MinString), zero, '0');
        return stoi(MaxString) - stoi(MinString);
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {9288, 909, 1000, 999, 1234, 9000};
    for (int num : testCases) {
        int result = sol.minMaxDifference(num);
        cout << "Input: " << num << " -> Difference: " << result << endl;
    }
    return 0;
}