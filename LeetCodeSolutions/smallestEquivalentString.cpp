#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Original version (no reference, no path compression)
    int findOriginal(vector<int> uf, int p) {
        if (uf[p] == -1)
            return p;
        return findOriginal(uf, uf[p]);
    }
    // Optimized version (reference & path compression)
    int findOptimized(vector<int>& uf, int p) {
        if (uf[p] == -1)
            return p;
        return uf[p] = findOptimized(uf, uf[p]);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr, bool useOptimized = true) {
        vector<int> parent(26, -1);
        for (int i = 0; i < s1.size(); i++) {
            int px = useOptimized ? findOptimized(parent, s1[i] - 'a') : findOriginal(parent, s1[i] - 'a');
            int py = useOptimized ? findOptimized(parent, s2[i] - 'a') : findOriginal(parent, s2[i] - 'a');
            if (px == py)
                continue;
            if (px > py)
                parent[px] = py;
            else
                parent[py] = px;
        }
        string result;
        for (char ch : baseStr) {
            int p = useOptimized ? findOptimized(parent, ch - 'a') : findOriginal(parent, ch - 'a');
            result.push_back(char(p + 'a'));
        }
        return result;
    }
};
int main() {
    vector<tuple<string, string, string>> testCases = {
        {"parker", "morris", "parser"},
        {"hello", "world", "hold"},
        {"leetcode", "programs", "sourcecode"},
        {"abc", "cde", "eed"},
        {"abc", "abc", "abc"}
    };
    Solution sol;
    cout << "Comparing Original vs Optimized:\n\n";
    for (int i = 0; i < testCases.size(); i++) {
        auto& [s1, s2, baseStr] = testCases[i];
        string originalRes = sol.smallestEquivalentString(s1, s2, baseStr, false);
        string optimizedRes = sol.smallestEquivalentString(s1, s2, baseStr, true);
        cout << "Test Case " << i + 1 << ":\n";
        cout << "BaseStr: " << baseStr << "\n";
        cout << "Original:  " << originalRes << "\n";
        cout << "Optimized: " << optimizedRes << "\n\n";
    }
    return 0;
}