#include <bits/stdc++.h>
using namespace std;

// 🔹 Your Original Version
class SolutionOriginal {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int Result = numBottles;
        while (numBottles >= numExchange) {
            int getFilled = numBottles / numExchange;
            Result += getFilled;
            numBottles = getFilled + (numBottles % numExchange);
        }
        return Result;
    }
};

// 🔹 Optimized Version
class SolutionOptimized {
public:
    int numWaterBottles(int bottles, int exchange) {
        int totalDrank = bottles;
        while (bottles >= exchange) {
            int newBottles = bottles / exchange;
            totalDrank += newBottles;
            bottles = newBottles + (bottles % exchange);
        }
        return totalDrank;
    }
};

int main() {
    SolutionOriginal original;
    SolutionOptimized optimized;

    // 🔹 Test cases: {numBottles, numExchange}
    vector<pair<int, int>> testCases = {
        {9, 3},
        {15, 4},
        {5, 5},
        {2, 3},
        {100, 10},
        {1, 2},
        {20, 5},
        {50, 7}
    };

    cout << "Comparing Original vs Optimized Solutions:\n";
    cout << "------------------------------------------\n";

    for (auto& [numBottles, numExchange] : testCases) {
        int resultOriginal = original.numWaterBottles(numBottles, numExchange);
        int resultOptimized = optimized.numWaterBottles(numBottles, numExchange);

        cout << "numBottles = " << numBottles
             << ", numExchange = " << numExchange
             << " | Original = " << resultOriginal
             << ", Optimized = " << resultOptimized
             << "\n";
    }

    return 0;
}
