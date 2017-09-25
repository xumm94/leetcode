    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int k = j + 1;
                int m = nums.size() - 1;
                
                while((k < nums.size()) &&(k < m))
                {
                    int diff = target - nums[i] - nums[j] - nums[k] - nums[m];
                    if(diff == 0)
                    {
                        vector<int> tmp(4, 0);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[k];
                        tmp[3] = nums[m];
                        result.push_back(tmp);
                         k++;
                        while(nums[k -1] == nums[k])
                                k++;
                        m--;
                        while(nums[m + 1] == nums[m])
                                m--;
                    }
                    else if(diff < 0)
                        {
                            m--;
                        while(nums[m + 1] == nums[m])
                                m--;
                        }
                    else
                        {
                             k++;
                        while(nums[k -1] == nums[k])
                                k++;
                        }
                        
                }

				while((j < nums.size() - 1) && nums[j + 1] == nums[j])
					j++;
            }
			while((i < nums.size() - 1) && nums[i + 1] == nums[i])
					i++;
        }
        return result;
    }


/*此类组合问题应当优先考虑对数组进行排序*/
