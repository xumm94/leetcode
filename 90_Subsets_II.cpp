    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res(1, vector<int>());
        if(nums.empty())
            return res;
        int last = nums[0];
        res.push_back(vector<int>(1, nums[0]));
        int last_begin = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int now_begin = res.size();
            if(last != nums[i])
            {
                last = nums[i];
                for(int j = 0, n = res.size(); j < n; j++)
                {
                    vector<int> tmp(res[j].begin(), res[j].end());
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }
            else
            {
                for(int j = last_begin, n = res.size(); j < n; j++)
                {
                    if(res[j].back() != nums[i])
                        continue;
                    vector<int> tmp(res[j].begin(), res[j].end());
                    tmp.push_back(nums[i]);
                    res.push_back(tmp);
                }
            }
            last_begin = now_begin;
        }
        
        return res;
        
    }


/*此题需要考虑有重复元素的情况，首先利用sort排序，使得相同的元素靠在一起。
需要两个中间变量记录上次重复的元素以及元素的位置。
假设集合为{1,2,2}
那么子集应该为：
{}，{1}，{2}，{1，2}，{1,2,2}
注意最后一个2，只需要在{1,2}这个后面加上2这个元素。
*/
