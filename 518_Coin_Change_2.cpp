class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(5001, 0);
        dp[0] = 1;
        sort(coins.begin(), coins.end());
        
        for(auto coin : coins)
        {
            for(int i = 1; i <= amount; i++)
                if(i - coin < 0)
                    continue;
                else
                    dp[i] += dp[i - coin];
        }
        return dp[amount];
        
    }
};

/*动态规划问题，转移的状态是最后一次付钱使用的硬币种类。
dp[i] = Σdp[i - coin]
*/
