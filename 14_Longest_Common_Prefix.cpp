    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
            return "";
        if(n == 1)
            return strs[0];
        
       string result = "";
        
        int n_0 = strs[0].size();
        
        for(int i = 0; i < n_0; i++)
        {
            char c = strs[0][i];
            for(int j = 1; j < n; j++)
            {
                if((strs[j].size() <= i) || strs[j][i] != c)
                    return result;    
            }
            result += c;
        }
        
        return result;
        
    }
