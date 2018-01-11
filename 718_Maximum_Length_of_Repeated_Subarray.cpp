class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.empty() || B.empty())
            return 0;
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int res = 0;

        for(int i = 0; i < B.size(); i++)
            if(A[0] == B[i])
                dp[0][i] = 1;
        
        for(int i = 0; i < A.size(); i++)
            if(A[i] == B[0])
                dp[i][0] = 1;
        
        for(int i = 1; i < A.size(); i++)
        {
            for(int j = 1; j < B.size(); j++)
            {
                if(A[i] == B[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
                
                res = max(res, dp[i][j]);
            }
        }
        
        return res;
    }
};

/*dp[i][j]表示以A[i]和B[j]为结尾的最长相同subarray。当A[i] != B[j]时，dp[i][j] = 0，这个0意味着一个中断点。
*/
