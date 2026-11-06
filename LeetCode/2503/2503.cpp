#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <ranges>
#include <tuple>
using namespace std;
// First Approach (Your first implementation)
class Solution1 {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        auto ans = vector<int>(size(queries));
        if (ranges::all_of(queries, [start = grid[0][0]](auto query) {
                                  return query <= start; })) {
            return ans;
        }
        auto sorted_query_indexes = vector<pair<int, int>>{};
        sorted_query_indexes.reserve(size(queries));
        for (auto [i, query] : views::enumerate(queries)) {
            sorted_query_indexes.emplace_back(query, i);
        }
        ranges::sort(sorted_query_indexes);
        auto q = queue<pair<int, int>>{};
        auto frontier = priority_queue(greater{},
          vector<tuple<int, int, int>>{{grid[0][0], 0, 0}});
        grid[0][0] = 0;
        auto score = 0;
        auto m = size(grid);
        auto n = size(grid[0]);
        for (auto [query, query_idx] : sorted_query_indexes) {
            while (!empty(frontier) && get<0>(frontier.top()) < query) {
                auto [_, i, j] = frontier.top();
                frontier.pop();
                q.emplace(i, j);
            }
            while (!empty(q)) {
                auto [i, j] = q.front();
                q.pop();
                ++score;
                if (i > 0 && grid[i - 1][j]) {
                    if (grid[i - 1][j] < query) {
                        q.emplace(i - 1, j);
                    } else {
                        frontier.emplace(grid[i - 1][j], i - 1, j);
                    }
                    grid[i - 1][j] = 0;
                }
                if (i < m - 1 && grid[i + 1][j]) {
                    if (grid[i + 1][j] < query) {
                        q.emplace(i + 1, j);
                    } else {
                        frontier.emplace(grid[i + 1][j], i + 1, j);
                    }
                    grid[i + 1][j] = 0;
                }
                if (j > 0 && grid[i][j - 1]) {
                    if (grid[i][j - 1] < query) {
                        q.emplace(i, j - 1);
                    } else {
                        frontier.emplace(grid[i][j - 1], i, j - 1);
                    }
                    grid[i][j - 1] = 0;
                }
                if (j < n - 1 && grid[i][j + 1]) {
                    if (grid[i][j + 1] < query) {
                        q.emplace(i, j + 1);
                    } else {
                        frontier.emplace(grid[i][j + 1], i, j + 1);
                    }
                    grid[i][j + 1] = 0;
                }
            }
            ans[query_idx] = score;
        }
        return ans;
    }
};
// Second Approach (Your second implementation)
class Solution2 {
#define currentLocation pair<int, int>
#define ValueCL pair<int, currentLocation>
    bool InBoundry(int& x, int& y, int& m, int& n) {
        return (x >= 0 and y >= 0 and x < m and y < n);
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        set<int> UniqueSortedQueries(queries.begin(), queries.end());
        unordered_map<int, int> QuerysCount;
        priority_queue<ValueCL, vector<ValueCL>, greater<ValueCL>>
            MinHeapStorage;
        MinHeapStorage.push(make_pair(grid[0][0], make_pair(0, 0)));
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> Visited(m, vector<bool>(n, false));
        Visited[0][0] = true;
        vector<int> Directions = {-1, 0, 1, 0, -1};
        int count = 0;
        for (int usq : UniqueSortedQueries) {
            while (!MinHeapStorage.empty()) {
                ValueCL Current = MinHeapStorage.top();
                MinHeapStorage.pop();
                int Value = Current.first;
                int X = Current.second.first;
                int Y = Current.second.second;
                if (Value >= usq) {
                    MinHeapStorage.push(Current);
                    break;
                }
                count++;
                for (int i = 0; i < 4; ++i) {
                    int newX = X + Directions[i];
                    int newY = Y + Directions[i + 1];
                    if (InBoundry(newX, newY, m, n) and !Visited[newX][newY]) {
                        Visited[newX][newY] = true;
                        MinHeapStorage.push(
                            make_pair(grid[newX][newY], make_pair(newX, newY)));
                    }
                }
            }
            QuerysCount[usq] = count;
        }
        vector<int> result;
        for (int q : queries)
            result.push_back(QuerysCount[q]);
        return result;
    }
};
int main() {
    // Test Input 1 for the first approach
    vector<vector<int>> grid1 = {{1, 2, 3}, {2, 5, 7}, {3, 5, 1}};
    vector<int> queries1 = {5, 6, 2};
    Solution1 sol1;
    vector<int> result1 = sol1.maxPoints(grid1, queries1);
    cout << "Results for the first approach: ";
    for (auto r : result1) {
        cout << r << " ";
    }
    cout << endl;
    // Test Input 2 for the second approach
    vector<vector<int>> grid2 = {{5, 2, 1}, {1, 1, 2}};
    vector<int> queries2 = {3};
    Solution2 sol2;
    vector<int> result2 = sol2.maxPoints(grid2, queries2);
    cout << "Results for the second approach: ";
    for (auto r : result2) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}