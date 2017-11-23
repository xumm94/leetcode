    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty())
            return result;
        if(nums.size() == 1)
        {
            result.push_back(to_string(nums[0]));
            return result;
        }
        int n = nums.size();
        int start = 0, end = 0;
        for(size_t index = 0; index < n - 1; index++)
        {
            if(nums[index + 1] - nums[index] != 1)
            {
                if(start == end)
                    result.push_back(to_string(nums[start]));
                else
                    result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
                
                start = index + 1;
                end = index + 1;
                
            }
            else
            {
                end++;
            }
        }
        
        if(start == end)
            result.push_back(to_string(nums[start]));
        else
            result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        return result;
        
    }



/*注意to_string这个库函数，可以将整数转换为字符串*/
