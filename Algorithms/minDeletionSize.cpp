#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1:
    // Build each column as a string and check if it is sorted
    int minDeletionSize_ColumnBuild(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();

        vector<string> colStr(cols, "");
        for (const string& s : strs) {
            for (int i = 0; i < cols; i++) {
                colStr[i].push_back(s[i]);
            }
        }

        int result = 0;
        for (const string& s : colStr) {
            string sortedCol = s;
            sort(sortedCol.begin(), sortedCol.end());
            if (s != sortedCol) {
                result++;
            }
        }
        return result;
    }

    // Approach 2:
    // Directly compare adjacent rows for each column
    int minDeletionSize_DirectCompare(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        int result = 0;

        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                if (strs[r][c] < strs[r - 1][c]) {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Hardcoded test cases
    vector<vector<string>> testCases = {
        {"cba", "daf", "ghi"},
        {"a", "b"},
        {"zyx", "wvu", "tsr"},
        {"abc", "bce", "cae"}
    };

    for (int i = 0; i < (int)testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Strings: ";
        for (const string& s : testCases[i]) {
            cout << s << " ";
        }
        cout << "\n";

        int ans1 = sol.minDeletionSize_ColumnBuild(testCases[i]);
        int ans2 = sol.minDeletionSize_DirectCompare(testCases[i]);

        cout << "Approach 1 (Column Build): " << ans1 << "\n";
        cout << "Approach 2 (Direct Compare): " << ans2 << "\n";
        cout << "---------------------------\n";
    }

    return 0;
}
