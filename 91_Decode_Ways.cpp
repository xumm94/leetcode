    int numDecodings(string s) {

        if(s.empty())
            return 0;
        
   
        if(s.size() == 1)
        {
            if(s[0] != '0')
                return 1;
            else
                return 0;
        }
        
        if(s.size() == 2)
        {
            if(s[0] == '0')
                return 0;
            if(s[1] == '0')
            {
                if(s[0] == '1' || s[0] == '2')
                    return 1;
                else
                    return 0;
            }
            if((s[0] == '1') || (s[0] == '2' && ((s[1] >= '0') && (s[1] <= '6'))))
                return 2;
            else
                return 1;
        }
        
        vector<int> dp(s.size(), 0);
         if(s[0] == '0')
                return 0;
        
        dp[0] = 1;
        
        if((s[0] == '1') || (s[0] == '2' && ((s[1] >= '0') && (s[1] <= '6'))))
                dp[1] = 2;
            else
                dp[1] = 1;
        
        if(s[1] == '0')
        {   
            if(s[0] == '1' || s[0] == '2')
                dp[1] = 1;
            else
                return 0;
        }
        
        
        
        
                
        
        
        for(int i = 2; i < s.size(); i++)
        {
            if(s[i] == '0')
            {
                if(s[i - 1] == '1' || s[i - 1] == '2')
                {   dp[i] =dp[i -2];
                    continue;
                }
                else
                    return 0;
            }
            if((s[i - 1] == '1') || (s[i - 1] == '2' && ((s[i] >= '0') && (s[i] <= '6'))))
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[s.size() - 1];
        
    }


/*典型的动态规划问题，和爬楼梯的问题相似，需要考虑以下问题：
某一位是0怎么办？
某一位是1怎么办？
某一位是2怎么办？（需要考虑后面一位）
*/
