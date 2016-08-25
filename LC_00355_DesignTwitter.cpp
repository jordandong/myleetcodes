/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed.
Your design should support the following methods:
1. postTweet(userId, tweetId): Compose a new tweet.
2. getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
3. follow(followerId, followeeId): Follower follows a followee.
4. unfollow(followerId, followeeId): Follower unfollows a followee.

Example:
Twitter twitter = new Twitter();
// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);
// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);
// User 1 follows user 2.
twitter.follow(1, 2);
// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);
// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);
// User 1 unfollows user 2.
twitter.unfollow(1, 2);
// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);

Hide Tags Hash Table Heap Design
*/

class Twitter {
private:
    unordered_map<int, unordered_set<int>> following_;
    unordered_map<int, deque<pair<size_t, int>>> messages_;
    size_t time_;
    size_t number_of_most_recent_tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
        time_ = 0;
        number_of_most_recent_tweets = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        messages_[userId].emplace_back(make_pair(++time_, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        using RIT = deque<pair<size_t, int>>::reverse_iterator;
        priority_queue<tuple<size_t, RIT, RIT>> heap;

        if (messages_[userId].size()) {
            heap.emplace(make_tuple(messages_[userId].rbegin()->first,
                                    messages_[userId].rbegin(),
                                    messages_[userId].rend()));
        }
        for (const auto& id : following_[userId]) {
            if (messages_[id].size()) {
                heap.emplace(make_tuple(messages_[id].rbegin()->first,
                                        messages_[id].rbegin(),
                                        messages_[id].rend()));
            }
        }
        vector<int> res;
        while (!heap.empty() && res.size() < number_of_most_recent_tweets) {
            const auto& top = heap.top();
            size_t t;
            RIT begin, end;
            tie(t, begin, end) = top;
            heap.pop();

            auto next = begin + 1;
            if (next != end) {
                heap.emplace(make_tuple(next->first, next, end));
            }

            res.emplace_back(begin->second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId && !following_[followerId].count(followeeId)) {
            following_[followerId].emplace(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId && following_[followerId].count(followeeId)) {
            following_[followerId].erase(followeeId);
        }        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
