#include <iostream>
#include <vector>
using namespace std;
// ------------------- CLASS-BASED IMPLEMENTATION -------------------
class Solution {
private:
    // Moves zero at index zi to the end
    void PushZero(vector<int>& n, int zi) {
        n.erase(n.begin() + zi);
        n.push_back(0);
    }
public:
    vector<int> applyOperations(vector<int>& n) {
        int ns = n.size();
        // Step 1: Merge adjacent equal numbers
        for (int i = 0; i < ns - 1; i++) {
            if (n[i] == n[i + 1] && n[i] != 0) {
                n[i] *= 2;
                n[i + 1] = 0;
            }
        }
        // Step 2: Move all zeros to the end
        int i = 0; 
        while (i < ns) {
            if (n[i] == 0) {
                PushZero(n, i);
                ns--; // Adjust size after removing an element
            } else {
                i++;
            }
        }
        return n;
    }
};
// ------------------- FUNCTION-BASED IMPLEMENTATION -------------------
void pushZero(vector<int>& n, int zi) {
    n.erase(n.begin() + zi);
    n.push_back(0);
}
vector<int> applyOperationsFunction(vector<int>& n) {
    int ns = n.size();
    // Step 1: Merge adjacent equal elements
    for (int i = 0; i < ns - 1; i++) {
        if (n[i] == n[i + 1] && n[i] != 0) {
            n[i] *= 2;
            n[i + 1] = 0;
        }
    }
    // Step 2: Move zeros to the end
    int i = 0;
    while (i < ns) {
        if (n[i] == 0) {
            pushZero(n, i);
            ns--; // Reduce size to prevent index shifting issues
        } else {
            i++;
        }
    }
    return n;
}
// ------------------- MAIN FUNCTION (TEST CASES) -------------------
int main() {
    // Test input
    vector<int> nums1 = {2, 2, 0, 4, 4, 8};
    vector<int> nums2 = nums1; // Copy for function-based approach
    // Class-based approach
    Solution sol;
    vector<int> result1 = sol.applyOperations(nums1);
    cout << "Class-Based Result: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    // Function-based approach
    vector<int> result2 = applyOperationsFunction(nums2);
    cout << "Function-Based Result: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}