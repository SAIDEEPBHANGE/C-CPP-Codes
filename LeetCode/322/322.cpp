#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    // Approach 1: DFS (Brute Force)
    int dfs(vector<int>& coins, int amount, int idx, int n) {
        if (amount == 0) {
            return 0;
        }
        if (idx >= n || amount < 0) {
            return 1e9;
        }
        // Take current coin (unlimited reuse)
        int take = 1 + dfs(coins, amount - coins[idx], idx, n);
        // Skip current coin
        int notTake = dfs(coins, amount, idx + 1, n);
        return min(take, notTake);
    }
public:
    int coinChangeDFS(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = dfs(coins, amount, 0, n);
        return ans >= 1e9 ? -1 : ans;
    }
    // Approach 2: BFS
    int coinChangeBFS(vector<int>& coins, int amount) {
        queue<int> q;
        vector<bool> visited(amount + 1, false);
        q.push(0);
        visited[0] = true;
        // Level represents the number of coins used.
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == amount) {
                    return level;
                }
                for (int coin : coins) {
                    long long next = (long long)curr + coin;
                    if (next <= amount && !visited[next]) {
                        q.push((int)next);
                        visited[next] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
    // Approach 3: Dynamic Programming (Tabulation)
    int coinChangeDP(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    // Hardcoded test cases
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 5}, 11},
        {{2}, 3},
        {{1, 3, 4}, 6},
        {{1}, 0},
        {{1, 2147483647}, 3},
        {{2, 5, 10, 1}, 27}
    };
    cout << "========== Coin Change Comparison ==========\n";
    for (int i = 0; i < testCases.size(); i++) {
        vector<int> coins = testCases[i].first;
        int amount = testCases[i].second;
        cout << "\nTest Case " << i + 1 << ":\n";
        cout << "Coins: ";
        for (int coin : coins) {
            cout << coin << " ";
        }
        cout << "\nAmount: " << amount << "\n";
        // DFS can be very slow for large test cases.
        if (amount <= 30) {
            cout << "DFS Answer: " 
                 << sol.coinChangeDFS(coins, amount) << "\n";
        } else {
            cout << "DFS Answer: Skipped (expensive brute force)\n";
        }
        cout << "BFS Answer: "
             << sol.coinChangeBFS(coins, amount) << "\n";
        cout << "DP Answer: "
             << sol.coinChangeDP(coins, amount) << "\n";
    }
    return 0;
}
