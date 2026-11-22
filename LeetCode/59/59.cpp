#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Approach 1: Simulation using Direction Vectors
    vector<vector<int>> generateMatrixDirection(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};
        int row = 0, col = 0;
        int dir = 0;
        for (int num = 1; num <= n * n; num++) {
            ans[row][col] = num;
            int nr = row + dr[dir];
            int nc = col + dc[dir];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n ||
                ans[nr][nc] != 0) {
                dir = (dir + 1) % 4;
            }
            row += dr[dir];
            col += dc[dir];
        }
        return ans;
    }
    // Approach 2: Optimized Spiral Traversal
    vector<vector<int>> generateMatrixSpiral(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        while (top <= bottom && left <= right) {
            // Left to Right
            for (int j = left; j <= right; j++)
                ans[top][j] = num++;
            top++;
            // Top to Bottom
            for (int i = top; i <= bottom; i++)
                ans[i][right] = num++;
            right--;
            // Right to Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans[bottom][j] = num++;
                bottom--;
            }
            // Bottom to Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans[i][left] = num++;
                left++;
            }
        }
        return ans;
    }
    // Approach 3: Layer-by-Layer Traversal
    vector<vector<int>> generateMatrixLayer(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int num = 1;
        int layers = (n + 1) / 2;
        for (int layer = 0; layer < layers; layer++) {
            int first = layer;
            int last = n - 1 - layer;
            // Top row
            for (int j = first; j <= last; j++)
                ans[first][j] = num++;
            // Right column
            for (int i = first + 1; i <= last; i++)
                ans[i][last] = num++;
            // Bottom row
            for (int j = last - 1; j >= first && first < last; j--)
                ans[last][j] = num++;
            // Left column
            for (int i = last - 1; i > first && first < last; i--)
                ans[i][first] = num++;
        }
        return ans;
    }
};
// Helper function to print matrix
void printMatrix(const string& approach,
                 vector<vector<int>> matrix) {
    cout << approach << ":\n";
    for (auto& row : matrix) {
        for (int num : row)
            cout << setw(4) << num;
        cout << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> testCases = {1, 2, 3, 4, 5};
    Solution sol;
    for (int t = 0; t < testCases.size(); t++) {
        int n = testCases[t];
        cout << "\n========== Test Case "
             << t + 1 << " (n = " << n << ") ==========\n\n";
        auto approach1 = sol.generateMatrixDirection(n);
        auto approach2 = sol.generateMatrixSpiral(n);
        auto approach3 = sol.generateMatrixLayer(n);
        printMatrix("Approach 1 - Direction Vectors", approach1);
        cout << "\n";
        printMatrix("Approach 2 - Boundary Traversal", approach2);
        cout << "\n";
        printMatrix("Approach 3 - Layer Traversal", approach3);
        cout << "\n";
    }
    return 0;
}
