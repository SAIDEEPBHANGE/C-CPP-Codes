#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int mask = n;
        while (mask) {
            mask >>= 1;
            n ^= mask;
        }
        return n;
    }
};

int main() {
    Solution sol;

    vector<int> testCases = {0, 1, 2, 3, 6, 9, 15, 37};
    cout << "Testing minimumOneBitOperations:\n";
    for (int n : testCases) {
        cout << "n = " << n << " -> result = " << sol.minimumOneBitOperations(n) << "\n";
    }

    return 0;
}
