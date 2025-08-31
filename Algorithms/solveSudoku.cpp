#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // For optimized solution
    bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
    vector<pair<int, int>> emptyCells;

    // Helper for box index
    inline int getBoxIndex(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }

    // Optimized O(1) check version
    bool solveOptimized(vector<vector<char>>& board, int pos) {
        if (pos == emptyCells.size()) return true;

        int i = emptyCells[pos].first;
        int j = emptyCells[pos].second;
        int boxIdx = getBoxIndex(i, j);

        for (int d = 0; d < 9; d++) {
            if (!rows[i][d] && !cols[j][d] && !boxes[boxIdx][d]) {
                board[i][j] = d + '1';
                rows[i][d] = cols[j][d] = boxes[boxIdx][d] = true;

                if (solveOptimized(board, pos + 1)) return true;

                board[i][j] = '.';
                rows[i][d] = cols[j][d] = boxes[boxIdx][d] = false;
            }
        }
        return false;
    }

    // Naive version with full check
    bool isValidNaive(vector<vector<char>>& b, int i, int j, char d) {
        for (int k = 0; k < 9; k++) {
            if (b[i][k] == d || b[k][j] == d)
                return false;
        }
        int startI = (i / 3) * 3, startJ = (j / 3) * 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (b[startI + r][startJ + c] == d)
                    return false;
            }
        }
        return true;
    }

    bool solveNaive(vector<vector<char>>& b) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValidNaive(b, i, j, d)) {
                            b[i][j] = d;
                            if (solveNaive(b)) return true;
                            b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    enum Mode { NAIVE, OPTIMIZED };

    void solveSudoku(vector<vector<char>>& board, Mode mode = OPTIMIZED) {
        if (mode == NAIVE) {
            solveNaive(board);
        } else {
            // Prepare lookup tables
            emptyCells.clear();
            memset(rows, 0, sizeof(rows));
            memset(cols, 0, sizeof(cols));
            memset(boxes, 0, sizeof(boxes));

            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        emptyCells.emplace_back(i, j);
                    } else {
                        int d = board[i][j] - '1';
                        rows[i][d] = cols[j][d] = boxes[getBoxIndex(i, j)][d] = true;
                    }
                }
            }
            solveOptimized(board, 0);
        }
    }

    // Helper for printing the board
    void printBoard(const vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    vector<vector<vector<char>>> testCases = {
        {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
        },
        {
            {'.','.','9','7','4','8','.','.','.'},
            {'7','.','.','.','.','.','.','.','.'},
            {'.','2','.','1','.','9','.','.','.'},
            {'.','.','7','.','.','.','2','4','.'},
            {'.','6','4','.','1','.','5','9','.'},
            {'.','9','8','.','.','.','3','.','.'},
            {'.','.','.','8','.','3','.','2','.'},
            {'.','.','.','.','.','.','.','.','6'},
            {'.','.','.','2','7','5','9','.','.'}
        }
    };

    Solution solver;

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Original Board #" << i + 1 << ":\n";
        solver.printBoard(testCases[i]);

        // Solve with optimized version
        solver.solveSudoku(testCases[i], Solution::OPTIMIZED);

        cout << "Solved Board #" << i + 1 << ":\n";
        solver.printBoard(testCases[i]);
    }

    return 0;
}
