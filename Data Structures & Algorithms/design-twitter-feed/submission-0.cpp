class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> vector of {timestamp, tweetId}

public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Max-heap stores: {timestamp, tweetId, user_id, index_in_user_vector}
        priority_queue<vector<int>> maxHeap;

        // Gather all relevant users (self + followees)
        unordered_set<int> users = following[userId];
        users.insert(userId);

        // Seed heap with the most recent tweet from each user
        for (int u : users) {
            auto& tweets = userTweets[u];
            if (!tweets.empty()) {
                int lastIdx = tweets.size() - 1;
                maxHeap.push({tweets[lastIdx].first, tweets[lastIdx].second, u, lastIdx});
            }
        }

        vector<int> feed;
        while (!maxHeap.empty() && feed.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int tweetId = top[1];
            int u = top[2];
            int idx = top[3];

            feed.push_back(tweetId);

            // If this user has an older tweet, push it to the heap
            if (idx > 0) {
                const auto& prevTweet = userTweets[u][idx - 1];
                maxHeap.push({prevTweet.first, prevTweet.second, u, idx - 1});
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
};