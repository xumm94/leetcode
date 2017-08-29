    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
            return 0;
        unordered_map<int, int> hash_table;
        int result = INT_MIN;
        
        for(int num : nums)
            hash_table[num] = 1;
        
        for(int num : nums)
        {
            int r = 1, tmp = num + 1;
            while(hash_table.count(tmp))
            {
                r++;
                hash_table.erase(tmp);
                tmp++;
            }
            
            tmp = num - 1;
            while(hash_table.count(tmp))
            {
                r++;
                hash_table.erase(tmp);
                tmp--;
            }
            
            result = max(result, r);
        }
        
        return result;
    
    }


/*通过unordered_map记录出现过的数值，然后向上向下搜索，寻找最大的边界*/
