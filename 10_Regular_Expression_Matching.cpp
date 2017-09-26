    bool isMatch(string s, string p) {
        size_t m = s.size(), n = p.size();
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || ( i > 0 && dp[i - 1][j] && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')));
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');    
            }
        }
        return dp[m][n];      
    }
/*此题属于较难的动态规划问题。
首先考虑其状态方程:
dp[i][j] 表示s[0,i)与p[0,j)相匹配
1.当p[j - 1] == '*'时，考虑两种情况
（1）.0次匹配
	此时，dp[i][j]的状态应该与dp[i][j-2]的状态相同
（2）.至少有1次匹配
	dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')
2.当p[j - 1] != '*'时
 只需考虑 dp[i - 1][j- 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.'

在第一次写的时候出现了错误，考虑m为何要从0开始：
假设s = aab， p=c*a*b，可以发现此时dp[0][2]应该是等于1的，也就是说，刚开始P中的某一段可能对应与S中的空。
*/ 
