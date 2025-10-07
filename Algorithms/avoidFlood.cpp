#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> result(n, -1);  // Initialize result with -1

        unordered_set<int> filledLakes;  // To track filled lakes
        map<int, queue<int>> lakeDays;  // To track the days each lake is filled

        // Step 1: Populate lakeDays with the days each lake is filled
        for (int i = 0; i < n; ++i) {
            if (rains[i] != 0) {
                // Store the day when lake `rains[i]` is filled
                lakeDays[rains[i]].push(i);
            }
        }

        // Step 2: Iterate through the rains array
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                // When rains[i] == 0, we try to drain a lake
                bool drained = false;

                // Check if we can drain a lake (one that was previously filled)
                for (auto& [lake, days] : lakeDays) {
                    if (!days.empty()) {
                        int day = days.front();
                        if (day > i) {  // Drain the lake on a future day
                            result[i] = lake;  // Assign the lake to be drained
                            days.pop();
                            drained = true;
                            break;
                        }
                    }
                }

                if (!drained) {
                    return {};  // No valid solution, return an empty vector
                }
            } else {
                // If it's a rainy day, we fill the lake `rains[i]`
                if (filledLakes.find(rains[i]) != filledLakes.end()) {
                    return {};  // Can't fill a lake that's already filled
                }
                filledLakes.insert(rains[i]);
            }
        }

        return result;  // Return the result after processing all days
    }
};

// Test case function
void runTestCases() {
    Solution solution;

    // Test case 1: Example case
    vector<int> rains1 = {1, 2, 0, 1, 2};
    vector<int> result1 = solution.avoidFlood(rains1);
    if (result1.empty()) {
        cout << "Test case 1: No solution" << endl;
    } else {
        cout << "Test case 1: ";
        for (int r : result1) cout << r << " ";
        cout << endl;
    }

    // Test case 2: No lakes to fill (all zeros)
    vector<int> rains2 = {0, 0, 0, 0};
    vector<int> result2 = solution.avoidFlood(rains2);
    if (result2.empty()) {
        cout << "Test case 2: No solution" << endl;
    } else {
        cout << "Test case 2: ";
        for (int r : result2) cout << r << " ";
        cout << endl;
    }

    // Test case 3: Impossible to avoid flooding
    vector<int> rains3 = {1, 2, 2, 1};
    vector<int> result3 = solution.avoidFlood(rains3);
    if (result3.empty()) {
        cout << "Test case 3: No solution" << endl;
    } else {
        cout << "Test case 3: ";
        for (int r : result3) cout << r << " ";
        cout << endl;
    }

    // Test case 4: A case where we can drain lakes
    vector<int> rains4 = {1, 0, 2, 0, 1, 2};
    vector<int> result4 = solution.avoidFlood(rains4);
    if (result4.empty()) {
        cout << "Test case 4: No solution" << endl;
    } else {
        cout << "Test case 4: ";
        for (int r : result4) cout << r << " ";
        cout << endl;
    }
}

int main() {
    // Run the test cases
    runTestCases();
    return 0;
}
