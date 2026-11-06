#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ump;
        for(int i = 0; i<s.size();i++){
            ump[s[i]] = max(i, ump[s[i]]);
        }
        vector<int> result;
        int end = 0;
        int preEnd = 0;
        for(int i = 0; i<s.size();i++){
            end = ump[s[i]];
            for(int j = i; j<end;j++){
                end = max(end, ump[s[j]]);
            }
            i = end;
            result.push_back(end - preEnd + 1);
            preEnd = end + 1;
        }
        return result;
    }
    void printVector(vector<int>& v) {
        for(int& i : v){
            cout << i << ", ";
        }
    }
};
int main() {
    Solution sol = Solution();
    vector<int> result01 = sol.partitionLabels("ababcbacadefegdehijhklij");
    vector<int> result02 = sol.partitionLabels("eccbbbbdec");
    cout << "Result 01 is "; 
    sol.printVector(result01);
    cout << endl;
    cout << "Result 02 is "; 
    sol.printVector(result02);
    cout << endl;
    return 0;
}