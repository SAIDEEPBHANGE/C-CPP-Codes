#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalMoney(int n) {
        int fullWeeks = n / 7;
        int remainingDays = n % 7;
        int total = 0;
        // Money from full weeks
        // Each week sum = 28 + 7 * week_index (0-based)
        total += (28 * fullWeeks) + (7 * (fullWeeks - 1) * fullWeeks) / 2;
        // Money from remaining days in the next week
        int start = 1 + fullWeeks; // starting value for the next Monday
        for (int i = 0; i < remainingDays; i++) {
            total += start + i;
        }
        return total;
    }
};
int main() {
    Solution sol;
    vector<int> testCases = {4, 10, 20, 26, 100};
    for (int n : testCases) {
        cout << "n = " << n 
             << " → totalMoney = " << sol.totalMoney(n) 
             << endl;
    }
    return 0;
}
