#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Optimized version (simpler and efficient)
    string clearStars(string s) {
        string result;
        for (char c : s) {
            if (c == '*') {
                int minIndex = 0;
                for (int i = 1; i < result.size(); ++i) {
                    if (result[i] <= result[minIndex]) {
                        minIndex = i;
                    }
                }
                result.erase(minIndex, 1);
            } else {
                result += c;
            }
        }
        return result;
    }
    // Map + index tracking version (more complex, same behavior)
    string clearStarsMapBased(string s) {
        string result;
        map<char, vector<int>> charIndices;
        for (char c : s) {
            if (c == '*') {
                for (auto& [ch, indices] : charIndices) {
                    if (!indices.empty()) {
                        int idxToRemove = indices.back(); 
                        indices.pop_back();
                        result.erase(result.begin() + idxToRemove);
                        for (auto& [_, vec] : charIndices) {
                            for (int& i : vec) {
                                if (i > idxToRemove) i--;
                            }
                        }
                        break;
                    }
                }
            } else {
                result.push_back(c);
                charIndices[c].push_back(result.size() - 1);
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<string> testCases = {
        "abc*d*",
        "a*b*c*",
        "z*x*y*",
        "abac*ca*",
        "abc*abc*abc*",
        "a*a*a*",
        "aab*b*",
        ""
    };
    cout << "Testing both versions on multiple test cases:\n\n";
    for (const auto& test : testCases) {
        string result1 = sol.clearStars(test);
        string result2 = sol.clearStarsMapBased(test);
        cout << "Input: " << test << "\n";
        cout << "clearStars (optimized):     " << result1 << "\n";
        cout << "clearStarsMapBased (map):   " << result2 << "\n";
        cout << (result1 == result2 ? "✅ Match\n" : "❌ Mismatch\n") << "\n";
    }
    return 0;
}