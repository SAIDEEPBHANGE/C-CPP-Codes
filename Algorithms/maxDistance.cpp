#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class Solution {
public:
    // -------- Original Version (per step check) --------
    int maxDistanceDetailed(string str, int k) {
        int maxDist = 0;
        int e = 0, w = 0, n = 0, s = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'E') e++;
            else if (str[i] == 'W') w++;
            else if (str[i] == 'N') n++;
            else if (str[i] == 'S') s++;
            int currDist = abs(e - w) + abs(n - s);
            int steps = i + 1;
            int wasted = steps - currDist;
            int recovered = min(2 * k, wasted);
            int totalDist = currDist + recovered;
            maxDist = max(maxDist, totalDist);
        }
        return maxDist;
    }
    // -------- Optimized Version (one pass) --------
    int maxDistanceOptimized(string str, int k) {
        int e = 0, w = 0, n = 0, s = 0;
        for (char ch : str) {
            if (ch == 'E') e++;
            else if (ch == 'W') w++;
            else if (ch == 'N') n++;
            else if (ch == 'S') s++;
        }
        int baseDist = abs(e - w) + abs(n - s);
        int totalSteps = str.length();
        int wasted = totalSteps - baseDist;
        int recovered = min(2 * k, wasted);
        return baseDist + recovered;
    }
    // -------- Dispatcher to choose which version to run --------
    int maxDistance(string str, int k, int version = 2) {
        if (version == 1) return maxDistanceDetailed(str, k);
        else return maxDistanceOptimized(str, k);
    }
};
// ------------------------ Test Harness ------------------------
int main() {
    Solution sol;
    vector<pair<string, int>> testCases = {
        {"ENWS", 1},
        {"ENWSENWS", 2},
        {"EEEWWWNNNSSS", 2},
        {"EEEENNNN", 0},
        {"ENWSENWSENWS", 3},
        {"NENENENWWSWSS", 2},
        {"E", 0},
        {"", 1}
    };
    int caseNum = 1;
    for (auto& [path, k] : testCases) {
        int res1 = sol.maxDistance(path, k, 1);  // Original
        int res2 = sol.maxDistance(path, k, 2);  // Optimized
        cout << "Test Case " << caseNum++ << ": Path=\"" << path << "\", k=" << k << "\n";
        cout << "  Original Version : " << res1 << "\n";
        cout << "  Optimized Version: " << res2 << "\n";
        cout << "--------------------------------------------------\n";
    }
    return 0;
}