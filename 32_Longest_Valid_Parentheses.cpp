    int longestValidParentheses(string s) {
        if(s.empty())
            return 0;
        stack<size_t> index;
        size_t len = 0;
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
/*注意此题有可能是左括号多也可能是右括号多。
考虑一下情形：
1.")()()"
  如果当前为')'，但是没有对应的左括号，说明新的一组开始。（对多个多余的')'也是适用的。
2."()()()"
  如果当前为右括号，栈中恰巧还有一个左括号，那么说明恰巧一个组结束。
3."(((()()()"
  如果左括号多余，说明可能包含新的一组（或者左括号就是多了），此时栈中top（）放着的正是多余左括号的坐标。
*/
