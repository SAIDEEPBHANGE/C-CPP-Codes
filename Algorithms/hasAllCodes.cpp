#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        Approach 1: Brute Force using set + substring
        Time Complexity: O(n * k)
        Space Complexity: O(2^k)
    */
    bool hasAllCodes_Set(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        set<int> codes;

        for (int i = 0; i <= n - k; i++) {
            int value = 0;
            for (int j = 0; j < k; j++) {
                value = (value << 1) + (s[i + j] - '0');
            }
            codes.insert(value);
        }

        return codes.size() == (1 << k);
    }

    /*
        Approach 2: Rolling Hash (Sliding Window + Bitmask)
        Time Complexity: O(n)
        Space Complexity: O(2^k)
    */
    bool hasAllCodes_Rolling(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        unordered_set<int> seen;
        int current = 0;
        int mask = (1 << k) - 1;

        for (int i = 0; i < n; i++) {
            current = ((current << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                seen.insert(current);
            }
        }

        return seen.size() == (1 << k);
    }

    /*
        Approach 3: Boolean Vector Optimization
        Avoids hash/set overhead
        Time Complexity: O(n)
        Space Complexity: O(2^k)
    */
    bool hasAllCodes_Vector(string s, int k) {
        int n = s.size();
        if (n < k) return false;

        int total = 1 << k;
        vector<bool> visited(total, false);
        int current = 0;
        int mask = total - 1;
        int count = 0;

        for (int i = 0; i < n; i++) {
            current = ((current << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                if (!visited[current]) {
                    visited[current] = true;
                    count++;
                }
            }
        }

        return count == total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases: {string, k}
    vector<pair<string, int>> testCases = {
        {"00110110", 2},
        {"00110", 2},
        {"0110", 1},
        {"0110", 2},
        {"0000000001011100", 4}
    };

    for (int i = 0; i < testCases.size(); i++) {
        string s = testCases[i].first;
        int k = testCases[i].second;

        cout << "Test Case " << i + 1 << ":\n";
        cout << "String: " << s << ", k = " << k << "\n";

        bool res1 = sol.hasAllCodes_Set(s, k);
        bool res2 = sol.hasAllCodes_Rolling(s, k);
        bool res3 = sol.hasAllCodes_Vector(s, k);

        cout << "Approach 1 (Set):        " << (res1 ? "true" : "false") << "\n";
        cout << "Approach 2 (Rolling):    " << (res2 ? "true" : "false") << "\n";
        cout << "Approach 3 (Vector):     " << (res3 ? "true" : "false") << "\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}