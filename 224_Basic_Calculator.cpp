    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        int index = 0;
        while(index < s.size())
        {
            while(index < s.size() && s[index] == ' ')
                index++;
            if(index == s.size())
               break;
            
            if((s[index] == '+') || (s[index] == '-') || (s[index] == '('))
                op.push(s[index++]);
            else if(s[index] == ')')
            {
                while(op.top() != '(')
                {
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(num2 + num1);
                    else
                        num.push(num2 - num1);
                    
                    op.pop();
                }
                op.pop();
                
                while(!op.empty() && op.top() != '(')
                {
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(num2 + num1);
                    else
                        num.push(num2 - num1);
                    op.pop();
                }
                index++;
            }
            else
            {
                int n = 0;
                while(index < s.size() && isdigit(s[index]))
                {
                    n = n * 10 + int(s[index++] - '0');
                    
                }
                num.push(n);
                
                while(!op.empty() && op.top() != '(')
                {
                    int num1 = num.top();
                    num.pop();
                    int num2 = num.top();
                    num.pop();
                    if(op.top() == '+')
                        num.push(num2 + num1);
                    else
                        num.push(num2 - num1);
                    op.pop();
                }
            }
                
        }
        return num.top();
        
    }


/*考察栈的知识，刚开始想的是将所有的运算符全部压入op栈，后来发现无法处理，当遇到')'的时候应当持续出栈，直到遇到'('
另外，第一次提交的时候出了一点问题，由字符串得到数字后忘了将数字压入数字栈。*/
