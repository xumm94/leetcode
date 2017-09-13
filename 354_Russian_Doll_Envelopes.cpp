    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto compare = [] (const pair<int, int> &lhs, const pair<int, int> &rhs)
        { return lhs.first == rhs.first ? lhs.second > rhs.second : lhs.first < rhs.first; };
     
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> dp;
        for(auto &e : envelopes)
        {
            auto it = lower_bound(dp.begin(), dp.end(), e.second);
            if(it == dp.end())
                dp.push_back(e.second);
            else if(e.second < *it)
                *it = e.second;
        }
        return dp.size();
        
    
    }



/*此题使用动态规划求解最长上升子序列，其实通过这个问题，发现了第300个题目的更好的一个解法
有一个地方花了一定的时间理解，最后dp的结果中的数值，并不一定是选择了的信封。（选择的信封不一定是对的，但是个数是对的）
*/
