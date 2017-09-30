    int strStr(string haystack, string needle) {
        if(haystack.empty() && needle.empty())
            return 0;
        
        if(needle.empty())
            return 0;
        
        int n = haystack.size();
        int m = needle.size();
        if(n < m)
            return -1;
        
        int max_start = n - m;
        for(int i = 0; i <= max_start; i++)
        {
            bool flag = 1;
            for(int j = 0; j < m; j++)
            {
                if(haystack[i + j] == needle[j])
                    continue;
                flag = 0;
                break;
            }
            if(flag)
                return i;
        }
        return -1;
        
    }
