#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp = 0;

public:
    Twitter() {}

    // Approach 1: Max Heap (Optimal)
    // Time: O(F + 10 log F)
    // Space: O(F)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timestamp, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;

        unordered_set<int> users = following[userId];
        users.insert(userId);

        for (int id : users) {
            if (!tweets[id].empty()) {
                int index = tweets[id].size() - 1;
                pq.push({tweets[id][index].first, id, index});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, id, index] = pq.top();
            pq.pop();

            feed.push_back(tweets[id][index].second);

            if (index > 0) {
                int prev = index - 1;
                pq.push({tweets[id][prev].first, id, prev});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    // Approach 2: Collect and Sort All Tweets
    // Time: O(T log T)
    // Space: O(T)
    vector<int> getNewsFeedSorting(int userId) {
        vector<pair<int, int>> allTweets;

        unordered_set<int> users = following[userId];
        users.insert(userId);

        for (int id : users) {
            for (auto& tweet : tweets[id]) {
                allTweets.push_back(tweet);
            }
        }

        sort(allTweets.rbegin(), allTweets.rend());

        vector<int> feed;

        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            feed.push_back(allTweets[i].second);
        }

        return feed;
    }

    // Approach 3: Maintain Top 10 Tweets
    // Time: O(10 * T)
    // Space: O(10)
    vector<int> getNewsFeedTop10(int userId) {
        vector<pair<int, int>> latest;

        unordered_set<int> users = following[userId];
        users.insert(userId);

        for (int id : users) {
            for (auto& tweet : tweets[id]) {
                latest.push_back(tweet);
                sort(latest.rbegin(), latest.rend());

                if (latest.size() > 10) {
                    latest.pop_back();
                }
            }
        }

        vector<int> feed;

        for (auto& tweet : latest) {
            feed.push_back(tweet.second);
        }

        return feed;
    }
};

void printFeed(const vector<int>& feed) {
    cout << "[ ";
    for (int id : feed) {
        cout << id << " ";
    }
    cout << "]\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<tuple<string, int, int>>> testCases = {
        {
            {"post", 1, 5},
            {"post", 1, 3},
            {"feed", 1, 0},
            {"follow", 1, 2},
            {"post", 2, 6},
            {"feed", 1, 0}
        },
        {
            {"post", 1, 10},
            {"post", 2, 20},
            {"follow", 1, 2},
            {"post", 2, 30},
            {"post", 1, 40},
            {"feed", 1, 0},
            {"unfollow", 1, 2},
            {"feed", 1, 0}
        },
        {
            {"post", 1, 100},
            {"post", 1, 200},
            {"post", 1, 300},
            {"post", 1, 400},
            {"post", 1, 500},
            {"post", 1, 600},
            {"post", 1, 700},
            {"post", 1, 800},
            {"post", 1, 900},
            {"post", 1, 1000},
            {"post", 1, 1100},
            {"feed", 1, 0}
        }
    };

    for (int tc = 0; tc < (int)testCases.size(); tc++) {
        Twitter t1, t2, t3;

        cout << "\n========== Test Case "
             << tc + 1 << " ==========\n";

        for (auto [op, a, b] : testCases[tc]) {
            if (op == "post") {
                t1.postTweet(a, b);
                t2.postTweet(a, b);
                t3.postTweet(a, b);
            }
            else if (op == "follow") {
                t1.follow(a, b);
                t2.follow(a, b);
                t3.follow(a, b);
            }
            else if (op == "unfollow") {
                t1.unfollow(a, b);
                t2.unfollow(a, b);
                t3.unfollow(a, b);
            }
            else if (op == "feed") {
                cout << "\nUser " << a << " News Feed:\n";

                cout << "Approach 1 (Max Heap): ";
                printFeed(t1.getNewsFeed(a));

                cout << "Approach 2 (Sorting): ";
                printFeed(t2.getNewsFeedSorting(a));

                cout << "Approach 3 (Top 10): ";
                printFeed(t3.getNewsFeedTop10(a));
            }
        }
    }

    return 0;
}