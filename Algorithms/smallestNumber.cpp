#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        while (true) {
            // Check if n+1 is a power of two, i.e., (n+1) & n == 0
            if (((n + 1) & n) == 0)
                return n;
            n++;
        }
    }
};

int main() {
    Solution sol;

    // Vector of test cases
    vector<int> testCases = {1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 17, 31, 32, 33};
    
    cout << "Testing smallestNumber(n):\n";
    for (int n : testCases) {
        int result = sol.smallestNumber(n);
        cout << "n = " << n << " -> smallestNumber = " << result << endl;
    }

    return 0;
}
