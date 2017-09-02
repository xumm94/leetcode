    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)
            return 0;
        vector<unordered_map<int, int>> dp(A.size());
        int result = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                long diff = long (A[i]) - A[j];
                if((diff > INT_MAX) || (diff < INT_MIN))
                    continue;
                int dif = int(diff);
                dp[i][dif] += 1;
                if(dp[j].count(dif) == 0)
                    continue;
                dp[i][dif] += dp[j][dif];
                result += dp[j][dif];
            }
        }
        
        return result;
    }
/*使用vector<unordered_map<int, int>>作为动态规划表，
dp[i[dif]表示以i为结尾，差为dif子列的个数
此处猛一看没有限制子列长度至少为3，
result += dp[j][dif] 是以前一个为结尾的个数，这保证了子列的长度至少为3 */
