#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    // Version 1: Original (with padding bug)
    vector<string> divideString_V1(string s, int k, char fill) {
        int n = s.size();
        vector<string> Result;
        int needK = k - (n % k);
        s.append(needK, fill);
        if (k > n)
            return {s};
        for (int i = 0; i < n; i += k) {
            string substr = s.substr(i, k);
            Result.push_back(substr);
        }
        return Result;
    }
    // Version 2: Fixed padding logic
    vector<string> divideString_V2(string s, int k, char fill) {
        int n = s.size();
        int remainder = n % k;
        if (remainder != 0) {
            s.append(k - remainder, fill);  // Only pad if needed
        }
        vector<string> result;
        for (int i = 0; i < s.size(); i += k) {
            result.push_back(s.substr(i, k));
        }
        return result;
    }
    // Version 3: Optimized (O(n) time, O(1) extra space)
    vector<string> divideString_V3(string s, int k, char fill) {
        int n = s.size();
        int remainder = n % k;
        if (remainder != 0) {
            s.append(k - remainder, fill);  // Pad to nearest multiple of k
        }
        vector<string> result;
        result.reserve((s.size() + k - 1) / k);  // Prevent reallocations
        for (int i = 0; i < s.size(); i += k) {
            result.emplace_back(s.begin() + i, s.begin() + i + k);
        }
        return result;
    }
};
// Helper to print vectors
void printVector(const vector<string>& vec) {
    cout << "[ ";
    for (const auto& str : vec) {
        cout << "\"" << str << "\" ";
    }
    cout << "]";
}
// Run test cases on all versions
void runTests() {
    Solution sol;
    vector<tuple<string, int, char>> testCases = {
        {"abcdefghi", 3, 'x'},
        {"abcd", 3, 'z'},
        {"a", 2, 'x'},
        {"helloworld", 5, '*'},
        {"abcde", 2, 'y'},
        {"", 4, 'x'},
        {"abc", 5, '_'}
    };
    int testNum = 1;
    for (const auto& [s, k, fill] : testCases) {
        cout << "Test Case " << testNum++ << ": s = \"" << s << "\", k = " << k << ", fill = '" << fill << "'\n";
        cout << "  V1: "; printVector(sol.divideString_V1(s, k, fill)); cout << "\n";
        cout << "  V2: "; printVector(sol.divideString_V2(s, k, fill)); cout << "\n";
        cout << "  V3: "; printVector(sol.divideString_V3(s, k, fill)); cout << "\n\n";
    }
}
int main() {
    runTests();
    return 0;
}