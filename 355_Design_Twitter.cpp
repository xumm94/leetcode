class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter()  {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time++, tweetId);
        return;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<tweet*, tweet*>> h;
        for(auto &f : following[userId])
        {
            auto &t = tweets[f];
            if(t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        auto &t = tweets[userId];
        if(t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);
        
        auto f = [](const pair<tweet*, tweet*>& lhs, const pair<tweet*, tweet*>& rhs)
        {
            return lhs.second->time < rhs.second->time;
        };
        make_heap(h.begin(), h.end(), f);
        const int n = 10;
        vector<int> res;
        res.reserve(n);
        for(int i = 0; i < 10 && !h.empty(); i++)
        {
            pop_heap(h.begin(), h.end(), f);
            
            auto &hb = h.back();
            res.push_back(hb.second->id);
            if(hb.first == hb.second--)
                h.pop_back();
            else
                push_heap(h.begin(), h.end(), f);
        }
        return res;
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(!(followerId == followeeId))
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
private:
    struct tweet
    {
        int time;
        int id;
        tweet(int time, int id) : time(time), id(id){};
    };
    int time;
    unordered_map<int, vector<tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
};


/*此题知识点：
1.lamada表达式。可以讲lamada表达式传递给泛型函数，注意lamada表达式的写法。
2.堆的知识。可以使用make_heap将一个vector转换为堆，使用pop_heap可以将对应的元素放置于vector的最后，push_heap将vector中的最后一个元素插入堆
*/
