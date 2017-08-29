 void my_per(vector<vector<int>> &res, vector<int> &nums, vector<int>& tmp, vector<bool> visited)
    {
        if(tmp.size() == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        
        for(int i = 0; i < nums.size();)
        {
            if(visited[i])
                continue;
            tmp.push_back(nums[i]);
            visited[i] = 1;
            my_per(res, nums, tmp, visited);
            tmp.pop_back();
            visited[i] = 0;
            
            int num = nums[i];
            while(num == nums[i])
                i++;
        }
        
       
    }

 vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if(nums.empty())
            return res;
        vector<int> tmp;
        vector<bool> visited;
        my_per(res, nums, tmp, visited);
        return res;       
    }

/*
主要需要考虑如何解决重复元素的问题，使用一个vector<bool>来判断一个
元素是否被使用*/

