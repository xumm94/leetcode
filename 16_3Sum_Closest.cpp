    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            
            if(j >= nums.size())
                break;
            while(k > j)
            {	
            
                int diff = target - nums[i] - nums[k] - nums[j];
                if(diff == 0)
                    return nums[i] + nums[j] + nums[k];
                
                if(abs(diff) < min_diff)
                {
                    min_diff = abs(diff);
                    result = nums[i] + nums[j] + nums[k];
                }
                if(diff < 0)
                    k--;
                else
                    j++;
            
              
            }
        }
        return result;
        
    }
