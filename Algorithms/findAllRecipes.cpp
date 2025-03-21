#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> points;
        unordered_map<string, int> indegree;
        unordered_set<string> supply{supplies.begin(), supplies.end()};
        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = 0;
            for (string& j : ingredients[i]) {
                if (supply.count(j) == 0) {
                    points[j].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }
        queue<string> q;
        for (auto& [r, i] : indegree) {
            if (i == 0)
                q.push(r);
        }
        vector<string> res;
        while (!q.empty()) {
            string cr = q.front();
            q.pop();
            res.push_back(cr);
            for (string& nr : points[cr]) {
                indegree[nr]--;
                if (indegree[nr] == 0)
                    q.push(nr);
            }
        }
        return res;
    }
};
int main() {
    Solution solution;
    // Sample input
    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {
        {"flour", "water"}, // bread requires flour and water
        {"bread", "meat"},  // sandwich requires bread and meat
        {"sandwich", "cheese"} // burger requires sandwich and cheese
    };
    vector<string> supplies = {"flour", "water", "meat", "cheese"};
    // Function call
    vector<string> result = solution.findAllRecipes(recipes, ingredients, supplies);
    // Output the result
    cout << "Possible recipes: ";
    for (const string& recipe : result) {
        cout << recipe << " ";
    }
    cout << endl;
    return 0;
}