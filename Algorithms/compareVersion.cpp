#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> splitVersion(string version) {
        vector<int> parts;
        stringstream ss(version);
        string part;
        while (getline(ss, part, '.')) {
            parts.push_back(stoi(part));
        }
        return parts;
    }

public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int part1 = (i < v1.size()) ? v1[i] : 0;
            int part2 = (i < v2.size()) ? v2[i] : 0;
            if (part1 < part2)
                return -1;
            if (part1 > part2)
                return 1;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    vector<pair<string, string>> testCases = {
        {"1.0.1", "1.0.2"},
        {"1.0.1", "1.0.1"},
        {"1.1", "1.0.1"},
        {"1.1.0", "1.1"},
        {"1.0.0", "1"},
        {"1.2", "1.10"},
        {"1.1.1", "1.1.1.0"},
        {"2.0.0", "2.0"},
        {"0.1", "1.0.0"}
    };
    
    // Testing
    for (const auto& testCase : testCases) {
        string version1 = testCase.first;
        string version2 = testCase.second;
        int result = solution.compareVersion(version1, version2);
        
        cout << "Comparing " << version1 << " and " << version2 << ": ";
        if (result == 0) {
            cout << "Equal\n";
        } else if (result == -1) {
            cout << version1 << " < " << version2 << "\n";
        } else {
            cout << version1 << " > " << version2 << "\n";
        }
    }
    
    return 0;
}
