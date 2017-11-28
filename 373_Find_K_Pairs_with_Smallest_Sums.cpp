    struct cmp {
        bool operator() (pair<int, int> &a, pair<int, int> &b) {
            return a.first + a.second < b.first + b.second;
        }
    };
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(q.size() < k)
                    q.push({nums1[i], nums2[j]});
                else
                {
                    if(nums1[i] + nums2[j] < q.top().first + q.top().second)
                    {
                        q.pop();
                        q.push({nums1[i], nums2[j]});
                    }
                }
            }
        }
        
        while(!q.empty())
        {
            res.push_back(q.top());
            q.pop();
        }
        
        return res;
        
    }




/*希望通过此题熟悉堆这种数据结构*/
