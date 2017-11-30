    string reverseStr(string s, int k) {
        if(s.empty())
            return "";
        if(s.size() <= k)
        {
            reverse(s.begin(), s.end());
            return s;
        }
    
        
        queue<char> re;
        stack<char> not_re;
        bool flag = 1;
        string result(s.size(), '0');
        for(int i = 0; i < s.size(); i++)
        {
            if(flag)
                re.push(s[i]);
            else
                not_re.push(s[i]);
            
            if((i + 1) % k == 0 || i + 1 == s.size())
            {
                int num = i;
                if(flag)
                {
                    while(!re.empty())
                    {
                        result[num] = re.front();
                        num--;
                        re.pop();
                    }
                }
                else
                {
                    while(!not_re.empty())
                    {
                        result[num] = not_re.top();
                        num--;
                        not_re.pop();
                    }
                }
                
                flag = !flag;
            }
        }
        
        return result;
        
    }
