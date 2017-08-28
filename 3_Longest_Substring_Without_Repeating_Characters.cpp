int lengthOfLongestSubstring(string s) {
        
        if(s.empty())
            return 0;
        
        unordered_map<char, int> windows;
        
        int front = 0;
        int back = 1;
        int max_len = 1;
        int cur_len = 1;
        windows[s[0]]++;
        
        while((front < s.size()) && (back < s.size()))
        {
            if(windows[s[back]] == 0)
            {
                windows[s[back]]++;
                back++;
                cur_len += 1;
                max_len = max(max_len, cur_len);
            }
            else
            {
                if(s[front] == s[back])
                {
                    front++;
                    back++;
                    continue;
                }
                while((s[front] != s[back]) && (front < back))
                {
                    windows[s[front]]--;
                    front++;
                }
                windows[s[front]]--;
                front++;
                cur_len = back - front;
                if(cur_len == 0)
                {
                    cur_len = 1;
                    windows[s[back]]++;
                    back++;             
                }
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
        
    }
