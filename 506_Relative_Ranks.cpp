    vector<string> findRelativeRanks(vector<int>& nums) {
        if(nums.empty())
            return vector<string>();

        auto f = [](int a, int b){return a > b; };
        
        vector<int> num_tmp(nums.begin(), nums.end());
        sort(num_tmp.begin(), num_tmp.end(), f );
        unordered_map<int, string> hash;
        for(size_t i = 0; i < num_tmp.size(); i++)
        {
            switch(i)
            {
                case 0:
                {
                    hash[num_tmp[i]] = "Gold Medal";
                    break;
                }
                
                case 1:
                {
                    hash[num_tmp[i]] = "Silver Medal";
                    break;
                }
                case 2:
                {
                    hash[num_tmp[i]] = "Bronze Medal";
                    break;
                }
                default :
                {
                    hash[num_tmp[i]] = to_string(i + 1);
                }
            }
        }
        
        vector<string> res(nums.size(), "");
        for(size_t i = 0; i < nums.size(); i++)
        {
            res[i] = hash[nums[i]];
        }
        return res;
       
        
        
    }



/*几个需要注意的地方
1.库函数to_string可以将整数转换为字符串
2.switch语句的具体用法
*/
