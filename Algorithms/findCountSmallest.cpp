#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll findCountSmallest(vector<int>& nums1, vector<int>& nums2, ll midProduct) {
        ll productsCount = 0;
        int n = nums2.size();
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1;
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    ll product = 1LL * nums1[i] * nums2[mid];
                    if(product <= midProduct) {
                        m = mid;
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
                productsCount += (m+1);
            } else {
                int l = 0;
                int r = n-1;
                int m = n;
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    ll product = 1LL * nums1[i] * nums2[mid];
                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                productsCount += (n - m);
            }
        }
        return productsCount;
    }
    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        ll result = 0;
        ll l = -1e10;
        ll r = 1e10;
        while(l <= r) {
            ll midProduct = l + (r-l)/2;
            ll countSmallest = findCountSmallest(nums1, nums2, midProduct);
            if(countSmallest >= k) {
                result = midProduct;
                r = midProduct-1;
            } else {
                l = midProduct+1;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<tuple<vector<int>, vector<int>, long long>> testCases = {
        {{1, 7}, {3, 4}, 3},                    // Expected: 12
        {{-4, -2, 0, 3}, {2, 4}, 6},            // Expected: 0
        {{-2, -1, 0, 1, 2}, {-3, -1, 2, 4, 5}, 3}, // Expected: -6
        {{1}, {1}, 1},                          // Expected: 1
        {{-3, -2, -1, 0, 1, 2, 3}, {-3, -2, -1, 0, 1, 2, 3}, 10} // Test with symmetric input
    };
    for (int i = 0; i < testCases.size(); ++i) {
        auto [nums1, nums2, k] = testCases[i];
        ll result = sol.kthSmallestProduct(nums1, nums2, k);
        cout << "Test Case " << i + 1 << ": " << result << endl;
    }
    return 0;
}