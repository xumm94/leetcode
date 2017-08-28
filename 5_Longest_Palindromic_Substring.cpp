
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        if(s.size() == 1)
            return s;
        

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int max_len = 1;
        int front;
        int back;
        
        for(int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        
        for(int len = 2; len <= s.size(); len++)
        {
            for(int i = 0, j = i + len - 1; j < s.size(); i++, j++)
            {
                if(s[i] == s[j])
                {
                    dp[i][j] = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 1;
                    if(dp[i][j] && (j - i + 1) > max_len)
                    {
                        front = i;
                        back = j;
                        max_len = j - i + 1;
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        return s.substr(front, max_len);
    }
