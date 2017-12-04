    int compress(vector<char>& chars) {
        int n = chars.size();

        vector<char> tmp = chars;
        chars.clear();
        
        for (int i = 0; i < n; ++i) 
        {
            int x = 1;
            while(i+1 < n && tmp[i] == tmp[i+1]) 
            {
                ++i;
                x++;
            }
            if (x == 1) {
                chars.push_back(tmp[i]);
            } else if (x >= 2) 
            {
                chars.push_back(tmp[i]);
                stack<char> s;
                while(x > 0) 
                {
                    s.push(char(x%10 +'0'));
                    x /= 10;
                }
                while(!s.empty())
                {
                    chars.push_back(s.top());
                    s.pop();
                }
            }
        }
        return chars.size();
    }
