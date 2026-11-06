#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Linear Search Algorithm
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Element found, return index
        }
    }
    return -1;  // Element not found
}
// Binary Search Algorithm (requires the array to be sorted)
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Check if target is at the mid index
        if (arr[mid] == target) {
            return mid;  // Element found, return index
        }
        // If target is smaller, it is in the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, it is in the right half
        else {
            left = mid + 1;
        }
    }
    return -1;  // Element not found
}
int main() {
    // Test Data
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int target = 22;
    // Perform Linear Search
    int linearResult = linearSearch(arr, target);
    if (linearResult != -1) {
        cout << "Linear Search: Element " << target << " found at index " << linearResult << endl;
    } else {
        cout << "Linear Search: Element " << target << " not found" << endl;
    }
    // Perform Binary Search (First, sort the array)
    sort(arr.begin(), arr.end());  // Sorting the array before performing binary search
    int binaryResult = binarySearch(arr, target);
    if (binaryResult != -1) {
        cout << "Binary Search: Element " << target << " found at index " << binaryResult << endl;
    } else {
        cout << "Binary Search: Element " << target << " not found" << endl;
    }
    return 0;
}