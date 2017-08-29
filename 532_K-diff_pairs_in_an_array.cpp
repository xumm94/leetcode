    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        size_t can_i = 0, can_j = 1;
        while(can_j < nums.size())
        {
        
            int diff = nums[can_j] - nums[can_i] - k;
            if(diff == 0)
            {
                res++;
                 int num = nums[can_i];
                while(can_i < nums.size() && num == nums[can_i])
                    can_i++;
                while(can_j <= can_i)
                    can_j++;

            }
            else if(diff < 0)
                can_j++;
            else
            {
                can_i++;
                while(can_j <= can_i)
                    can_j++;
            }
        

        }
        
        return res;
    }
