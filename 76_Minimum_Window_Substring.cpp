    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        vector<int> count(128,0);
        vector<bool> use(128,false);
        int min_len = INT_MAX, start = 0, end = 0, min_start, min_end, curr_len, num = 0;
        for(auto &c : t)
        {
            count[c]++;
            use[c] = 1;
        }
        
       while(end < s.size())
       {
           if(!use[s[end]])
           {
               end++;
               continue;
           }
           
           if(count[s[end]]-- > 0)
               num++;
           if(num == t.size())
           {
               while(start != end )
               {
                   if(!use[s[start]])
                   {
                       start++;
                       continue;
                   }
                   if(count[s[start]] < 0)
                   {
                       count[s[start]]++;
                       start++;
                       continue;
                   }
                   else
                       break;
               }
               
               curr_len = end - start + 1;
               if(curr_len < min_len)
               {
                   min_len = curr_len;
                   min_start = start;
                   min_end = end;
               }
                 
           }
           end++;
       }
        
        if(min_len == INT_MAX)
            return "";
        else
            return s.substr(min_start, min_len);
        
    }



/*分析过程见博客
http://blog.csdn.net/zhangxiao93/article/details/49892665
非常详细*/
