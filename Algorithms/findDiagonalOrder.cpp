#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (!mat.size())
            return vector<int>();
        vector<int> res;
        int m = mat.size(), n = mat[0].size();
        for (int d = 0; d < (m + n - 1); d++) {
            int r = 0, c = 0;
            if (!(d % 2)) {
                r = min(d, m - 1);
                c = d - r;
                while (r >= 0 && c < n) {
                    res.push_back(mat[r][c]);
                    r--;
                    c++;
                }
            } else {
                c = min(d, n - 1);
                r = d - c;
                while (c >= 0 && r < m) {
                    res.push_back(mat[r][c]);
                    r++;
                    c--;
                }
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result = sol.findDiagonalOrder(mat1);
    cout << "Diagonal traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    // Additional test cases
    vector<vector<int>> mat2 = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    result = sol.findDiagonalOrder(mat2);
    cout << "Diagonal traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
