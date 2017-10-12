    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
       int max_pre = nums[0];
       int min_pre = nums[0];
       int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            int a = max_pre * nums[i];
            int b = min_pre * nums[i];
            
            max_pre = max(max(a,b), nums[i]);
            min_pre = min(min(a,b), nums[i]);
            
            result = max(result, max_pre);
        }
        return result;
    }
