#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& ns) {
        int n = ns.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++) {
            if (!ns[i]) {
                ns[i] ^= 1;
                ns[i + 1] ^= 1;
                ns[i + 2] ^= 1;
                ++ans;
            }
        }
        if (!ns[n - 2] || !ns[n - 1])
            return -1;
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> ns = {0, 0, 0, 0, 1}; // Example input, change as needed
    int result = solution.minOperations(ns);
    if (result != -1)
        cout << "Minimum operations: " << result << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}