    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for(int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = i - 1; k < j; k++)
                {
                    int val = max(dp[i - 1][k], sums[j] - sums[k]);
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        
        
        
        return dp[m][n];
    }


/*动态规划问题
设dp[i][j]为将前j个元素划分为i段得到的最小值，其中i的取值范围为[1,j]
重点是更新公式
dp[i][j + 1] = min(dp[i - 1][k]), k的取值范围是[i - 1, j)
三个循环，注意理解。
*/
