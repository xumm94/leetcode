    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        stack<size_t> index;
        size_t len = 0;
        size_t len_now = 0;
        size_t lastindex = 0;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                index.push(i);
            else
            {
                if(index.empty())
                    lastindex = i + 1;
                else
                {
                      index.pop();
                    if(index.empty())
                        len = max(len, i - lastindex + 1);
                    else
                        len = max(len, i - index.top());
                }
            }
        }
        return len;
        
    }
