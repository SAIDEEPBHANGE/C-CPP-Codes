#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
    ---------------------------------------------------------
    Approach 1: Direct Simulation on String (Modify String)
    Time Complexity: O(n^2) worst case
    ---------------------------------------------------------
    */
    int numSteps_simulation(string s) {
        int count = 0;
        while (s != "1") {
            // If even -> divide by 2 (remove last bit)
            if (s.back() == '0') {
                s.pop_back();
            } 
            // If odd -> add 1
            else {
                int i = s.size() - 1;
                // Propagate carry
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) {
                    s = "1" + s;  // overflow case
                } else {
                    s[i] = '1';
                }
            }
            count++;
        }
        return count;
    }
    /*
    ---------------------------------------------------------
    Approach 2: Optimized Carry-Based Traversal
    Time Complexity: O(n)
    Space Complexity: O(1)
    ---------------------------------------------------------
    */
    int numSteps_optimized(string s) {
        int steps = 0;
        int carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) == 1) {
                // odd case
                steps += 2;
                carry = 1;
            } else {
                // even case
                steps += 1;
            }
        }
        return steps + carry;
    }
    /*
    ---------------------------------------------------------
    Approach 3: Using Big Integer (for demonstration)
    Uses manual binary addition and division simulation
    Time Complexity: O(n^2)
    ---------------------------------------------------------
    */
    int numSteps_bigint(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back();  // divide by 2
            } else {
                // add 1 manually
                int carry = 1;
                for (int i = s.size() - 1; i >= 0 && carry; i--) {
                    int bit = (s[i] - '0') + carry;
                    s[i] = (bit % 2) + '0';
                    carry = bit / 2;
                }
                if (carry) {
                    s = "1" + s;
                }
            }
            steps++;
        }
        return steps;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<string> testCases = {
        "1",
        "10",
        "11",
        "1101",
        "1111011110000011100000110001011011110010111001010111110001"
    };
    cout << "Comparing Different Approaches:\n\n";
    for (const string& s : testCases) {
        cout << "Input: " << s << "\n";
        int ans1 = sol.numSteps_simulation(s);
        int ans2 = sol.numSteps_optimized(s);
        int ans3 = sol.numSteps_bigint(s);
        cout << "Simulation Approach      : " << ans1 << "\n";
        cout << "Optimized Carry Approach : " << ans2 << "\n";
        cout << "BigInt Simulation        : " << ans3 << "\n";
        cout << "--------------------------------------\n";
    }
    return 0;
}