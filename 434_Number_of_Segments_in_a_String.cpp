   int countSegments(string s) {
        if(s.empty())
            return 0;
        s += ' ';
        int result = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ' ' && s[i - 1] != ' ')
                result++;
        }
        return result;
    }



/*分片，当前字符是空格，前一个字符不是空格就是一个分片*/
