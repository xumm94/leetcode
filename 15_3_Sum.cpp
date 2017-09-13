    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int sum;
        for(int i = 0; i < nums.size(); i++)
        {
            int target = nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            
            while(front < back)
            {
                sum = target + nums[front] + nums[back];
                if(sum > 0)
                    back--;
                else if(sum < 0)
                    front++;
                else
                {
                    vector<int> triple(3,0);
                    triple[0] = nums[i];
                    triple[1] = nums[front];
                    triple[2] = nums[back];
                    result.push_back(triple);
                    
                    while(front < back && nums[front] == triple[1])
                        front++;
                    while(front < back && nums[back] == triple[2])
                        back--;
                }
    
            }
            while((i + 1 < nums.size()) && (nums[i] == nums[i+1]))
                i++;
        }
        return result;
    }
