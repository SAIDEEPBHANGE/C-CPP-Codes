#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
using namespace std;
class NumberContainers {
private:
    map<int, int> indexToNumber;                  // index -> number
    unordered_map<int, set<int>> numberToIndices; // number -> set of indices
public:
    NumberContainers() {}
    // Change the number at a specific index
    void change(int index, int number) {
        // Check if index already exists
        if (indexToNumber.find(index) != indexToNumber.end()) {
            int oldNumber = indexToNumber[index];
            if (oldNumber == number)
                return; // No actual change
            // Remove the index from the old number's index set
            numberToIndices[oldNumber].erase(index);
        }
        // Update mapping
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }
    // Find the smallest index filled with the given number
    int find(int number) {
        if (numberToIndices.find(number) != numberToIndices.end() &&
            !numberToIndices[number].empty()) {
            return *numberToIndices[number].begin(); // Return smallest index
        }
        return -1;
    }
};
int main() {
    // Initialize NumberContainers object
    NumberContainers nc;
    // Define test cases as a vector of vectors
    vector<vector<int>> testCases = {
        {10},                   // find(10) should return -1
        {2, 10},                // change(2, 10)
        {1, 10},                // change(1, 10)
        {3, 10},                // change(3, 10)
        {5, 10},                // change(5, 10)
        {10},                   // find(10) should return 1 (smallest index for 10)
        {1, 20},                // change(1, 20) (index 1 changes to 20)
        {10},                   // find(10) should return 2 (smallest index for 10 after change)
    };
    // Run test cases
    for (auto& testCase : testCases) {
        if (testCase.size() == 1) {
            // Find test case
            cout << "find(" << testCase[0] << "): " << nc.find(testCase[0]) << endl;
        } else if (testCase.size() == 2) {
            // Change test case
            nc.change(testCase[0], testCase[1]);
            cout << "change(" << testCase[0] << ", " << testCase[1] << ")" << endl;
        }
    }
    return 0;
}