    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0] >= s ? 1 : 0;
        
        int len = INT_MAX;
        int sum = 0;
        int start = 0;
        int end = 0;
        while(end < nums.size())
        {
            while(sum < s && end < nums.size())
                sum += nums[end++];
            while(sum >= s)
            {
                len = min(len, end - start);
                sum -= nums[start++];
            } 
        }
        
        if(len == INT_MAX)
            return 0;
        else
            return len;
    }



/*左右两个指针，当sum小于s时end右移，当sum大于等于s时，start左移，一开始while里面用的是两个if语句，边界条件不好处理，且效率低。*/

