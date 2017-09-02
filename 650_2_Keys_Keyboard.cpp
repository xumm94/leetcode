    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 2; i <= n; i++)
        {
            dp[i] = i;
            for(int j = i - 1; j > 1; j--)
            {
                if(i % j == 0)
                    dp[i] = min(dp[i], dp[j] + i / j);
            }
        }
        return dp[n];
        
    }
/*和爬楼梯的题目相似*/
