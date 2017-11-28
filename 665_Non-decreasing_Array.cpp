    bool checkPossibility(vector<int>& nums) {
        if(nums.empty()  || nums.size() == 1)
            return 1;
        bool found = false;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                if(found)
                    return false;
                found = true;
                if(i >= 2 && nums[i] < nums[i - 2])
                {
                    nums[i] = nums[i - 1];
                }
    
            }
        }
        
        return true;
        
        
    }

