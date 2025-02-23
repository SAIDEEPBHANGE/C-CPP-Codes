#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Structure to represent an item with value and weight
struct Item {
    int value;
    int weight;
    // Constructor for easy initialization
    Item(int v, int w) : value(v), weight(w) {}
};
// Fractional Knapsack Problem (Greedy Approach)
double fractionalKnapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<pair<double, int>> ratio(n);
    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = { (double)items[i].value / items[i].weight, i };
    }
    // Sort items by value/weight ratio in descending order
    sort(ratio.rbegin(), ratio.rend());
    double totalValue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        int idx = ratio[i].second;
        if (items[idx].weight <= W) {
            W -= items[idx].weight;
            totalValue += items[idx].value;
        } else {
            totalValue += items[idx].value * ((double)W / items[idx].weight);
            break;
        }
    }
    return totalValue;
}
// 0/1 Knapsack Problem (Dynamic Programming)
int knapsack01(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
// Bounded Knapsack Problem (Dynamic Programming)
int knapsackBounded(int W, vector<Item>& items, vector<int>& limits) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            for (int k = 0; k <= limits[i - 1] && k * items[i - 1].weight <= w; k++) {
                dp[i][w] = max(dp[i][w], dp[i - 1][w - k * items[i - 1].weight] + k * items[i - 1].value);
            }
        }
    }
    return dp[n][W];
}
// Unbounded Knapsack Problem (Dynamic Programming)
int knapsackUnbounded(int W, vector<Item>& items) {
    int n = items.size();
    vector<int> dp(W + 1, 0);
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (items[i].weight <= w) {
                dp[w] = max(dp[w], dp[w - items[i].weight] + items[i].value);
            }
        }
    }
    return dp[W];
}
int main() {
    // Example data for Knapsack Problems
    vector<Item> items = { Item(60, 10), Item(100, 20), Item(120, 30) };
    int W = 50; // Knapsack capacity
    // Fractional Knapsack Problem
    cout << "Fractional Knapsack Value: " << fractionalKnapsack(W, items) << endl;
    // 0/1 Knapsack Problem
    cout << "0/1 Knapsack Maximum Value: " << knapsack01(W, items) << endl;
    // Bounded Knapsack Problem
    vector<int> limits = { 2, 3, 1 }; // Maximum number of each item
    cout << "Bounded Knapsack Maximum Value: " << knapsackBounded(W, items, limits) << endl;
    // Unbounded Knapsack Problem
    cout << "Unbounded Knapsack Maximum Value: " << knapsackUnbounded(W, items) << endl;
    return 0;
}