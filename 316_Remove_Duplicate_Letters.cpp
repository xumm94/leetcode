    string removeDuplicateLetters(string s) {

        if(s.empty())
            return "";
        vector<int> num_count(26, 0);
        vector<bool> visited(26, 0);
        
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++)
            num_count[int(s[i] - 'a')]++;
        
        int index;
        
        for(int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';
            num_count[index]--;
            if(visited[index])
                continue;
            
            while(!st.empty() && s[i] < st.top() && num_count[st.top() - 'a'] != 0)
            {
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(s[i]);
            visited[index] = 1;
        }
        
        string result;
       while(!st.empty())
       {
           result = st.top() + result;
           st.pop();
       }
        
        return result;
    }
/*
注意第22-26行的代码，可以使用反证法或者数学归纳法证明栈中字母的顺序一定全部是倒过来的
*/
