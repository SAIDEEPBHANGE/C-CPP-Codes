#include <bits/stdc++.h>
using namespace std;
class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq2[oldVal]--;
        if (freq2[oldVal] == 0)
            freq2.erase(oldVal);
        nums2[index] += val;
        freq2[nums2[index]]++;
    }
    int count(int tot) {
        int cnt = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freq2.count(complement)) {
                cnt += freq2[complement];
            }
        }
        return cnt;
    }
};
// Test runner
int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4};
    FindSumPairs* obj = new FindSumPairs(nums1, nums2);
    cout << "Initial count for total = 5: " << obj->count(5) << endl;  // 2 (1+4, 2+3)
    obj->add(0, 1);  // nums2 becomes [4, 4]
    cout << "Count after add(0, 1) for total = 5: " << obj->count(5) << endl;  // 1 (1+4)
    obj->add(1, -2);  // nums2 becomes [4, 2]
    cout << "Count after add(1, -2) for total = 6: " << obj->count(6) << endl;  // 2 (2+4, 3+3)
    obj->add(1, 2);  // nums2 becomes [4, 4]
    cout << "Count after add(1, 2) for total = 7: " << obj->count(7) << endl;  // 2 (3+4, 3+4)
    // Additional test case
    vector<int> nums1b = {0, 1};
    vector<int> nums2b = {0, 0, 1};
    FindSumPairs* obj2 = new FindSumPairs(nums1b, nums2b);
    cout << "Initial count for total = 1: " << obj2->count(1) << endl; // 3 (0+1, 1+0, 1+0)
    obj2->add(0, 2); // nums2 becomes [2, 0, 1]
    cout << "Count after add(0, 2) for total = 2: " << obj2->count(2) << endl; // 1 (0+2)
    delete obj;
    delete obj2;
    return 0;
}