#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& r, int c) {
        long long low = 1;
        long long minEle = *min_element(r.begin(), r.end());
        long long high = minEle * c * c;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ac = 0;
            for (int i : r) {
                ac += sqrt(mid / i);
            }
            if (ac >= c) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    
    // Example usage:
    vector<int> r = {4, 2, 3};  // Repair rates of the machines
    int c = 10;                 // Number of cars to repair
    
    long long result = solution.repairCars(r, c);
    
    cout << "Minimum time to repair " << c << " cars: " << result << endl;

    return 0;
}
