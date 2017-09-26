void reverseWords(string &s) {
    if(s.empty())
        return ;
    s += ' ';
    stack<string> dict;
    size_t start = 0, n = 1;
    while(start < s.size() && s[start] == ' ')
        start++;
    if(start == s.size())
    {
        s = "";
        return;
    }
    s = s.substr(start);
    start = 0;
    for(size_t i = 0; i < s.size();)
    {
        if(s[i] == ' ')
        {
            string word = s.substr(start, i - start);
            dict.push(word);
            while(i < s.size() && s[i] == ' ')
                i++;
            start = i;
        }
        else
            i++;
    }
    string res;
    while(dict.size() > 1)
    {
        res += dict.top();
        dict.pop();
        res += ' ';
    }
    res += dict.top();
    swap(s,res);
    return ;

    }
