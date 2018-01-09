class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        vector<int> next(101, INT_MAX);
        
        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            int earliest = INT_MAX;
            for(int j = temperatures[i] + 1; j < 101; j++)
            {
                if(next[j] != INT_MAX)
                    earliest = min(earliest, next[j]);     
            }
            
            if(earliest != INT_MAX)
                result[i] = earliest - i;
            
            next[temperatures[i]] = i;
        }
        
        
        return result;
        
    }
};


/*看到这种输入有范围的就应该考虑动态规划或者哈希表*/
