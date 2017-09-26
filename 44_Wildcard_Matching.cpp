    bool isMatch(string s, string p) {
        size_t m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, 0));
        dp[0][0] = 1;
        for(size_t i = 0; i <= m; i++)
        {
            for(size_t j = 1; j <= n; j++)
            {
                if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
            }
        }
        return dp[m][n];
    }
