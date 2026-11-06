#include <bits/stdc++.h>
using namespace std;
class Spreadsheet {
private:
    vector<vector<int>> grid;
    // Converts cell label like "A1" to (row, col)
    pair<int, int> parseCell(const string& cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1;
        return {row, col};
    }
    // Gets value of operand (either direct number or cell reference)
    int getOperandValue(const string& operand) {
        if (isdigit(operand[0]) || (operand[0] == '-' && isdigit(operand[1]))) {
            return stoi(operand);
        }
        auto [row, col] = parseCell(operand);
        if (row >= 0 && row < (int)grid.size() && col >= 0 && col < 26) {
            return grid[row][col];
        }
        return 0;
    }
public:
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    void setCell(const string& cell, int value) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = value;
    }
    void resetCell(const string& cell) {
        auto [row, col] = parseCell(cell);
        grid[row][col] = 0;
    }
    // Evaluates formulas like "=A1+B2" or "=A1+5"
    int getValue(const string& formula) {
        if (formula.empty() || formula[0] != '=')
            return 0;
        size_t plusPos = formula.find('+');
        if (plusPos == string::npos)
            return 0;
        string left = formula.substr(1, plusPos - 1);
        string right = formula.substr(plusPos + 1);
        return getOperandValue(left) + getOperandValue(right);
    }
};
int main() {
    Spreadsheet sheet(5); // Create a spreadsheet with 5 rows
    // Test cases
    sheet.setCell("A1", 10);
    sheet.setCell("B2", 20);
    sheet.setCell("C3", -5);
    vector<string> formulas = {
        "=A1+B2",   // 10 + 20 = 30
        "=A1+5",    // 10 + 5 = 15
        "=10+20",   // 10 + 20 = 30
        "=C3+A1",   // -5 + 10 = 5
        "=A1+C3",   // 10 + (-5) = 5
        "=A1+B5",   // 10 + 0 = 10 (B5 is unset)
        "=B2+Z1",   // 20 + 0 = 20 (Z1 is out of range in row)
        "=B2+X6"    // 20 + 0 = 20 (X6 is out of range in row)
    };
    for (const string& formula : formulas) {
        cout << "Formula " << formula << " = " << sheet.getValue(formula) << endl;
    }
    // Resetting a cell
    sheet.resetCell("A1");
    cout << "After resetting A1, =A1+B2 = " << sheet.getValue("=A1+B2") << endl; // Should be 0 + 20 = 20
    return 0;
}
