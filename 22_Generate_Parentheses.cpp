    void helper(vector<string> &result, string now, int n, int m)
    {
        if(n == 0 && m == 0)
            result.push_back(now);
        
        if(n > 0)
            helper(result,now + '(',n - 1,m);
        
        if((m > n) && (m > 0))
            helper(result, now + ')', n, m - 1);
    
    }


    vector<string> generateParenthesis(int n) {
       if(n == 0)
           return vector<string>();
        vector<string> result;
        helper(result,"",n,n);
        return result;      
    }


/*回溯问题，此题较为典型，不是自己做出来的,直接看代码可能不是太好理解，可以借助二叉树来理解*/
