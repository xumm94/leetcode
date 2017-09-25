    bool isValid(string s) {
        if(s.empty()) return 1;
        if(s.size() % 2) return 0;
        stack<char> left;
        char left_char;
        
        for(int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
                case '(':
                    {
                        left.push(s[i]);
                        break;
                    }
                case '[':
                    {
                        left.push(s[i]);
                        break;
                    }
                case '{':
                    {
                        left.push(s[i]);
                        break;
                    }
                    
                case'}':
                    {

                        if(left.empty() || left.top() != '{')
                            return 0;
                            left.pop();
                        break;
                    }
                case')':
                    {
                        
                        if(left.empty() || left.top() != '(' )
                            return 0;
                        left.pop();
                        break;
                    }
                case']':
                    {

                        if(left.empty() || left.top() != '[')
                            return 0;
                            left.pop();
                        break;
                    }
                
                
            }
        }
        return left.empty();
        
    }
