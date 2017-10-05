    int numTrees(int n) {
        vector<int> dp(n + 1,0);
        dp[0] = 1;
        dp[1] = 1;
        int sum = 0;
        for(int i = 2; i <= n; i++)
        {
            sum = 0;
            for(int j = 0; j < i; j++)
            {
                sum += dp[j] * dp[i - 1 - j] ;
            }
            dp[i] = sum;
        }
        return dp[n];
        
    }

/*设共有n个元素，[0,n - 1]。任意取其中的某个数i作为根节点，[0, i - 1]作为左子树，[i + 1, n - 1]作为右子树。遍历，双重循环就能得到最终的结果。*/

