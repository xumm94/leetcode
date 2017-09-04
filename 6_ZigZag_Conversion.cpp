    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        
        const int len = s.length();
        vector<string> str(numRows, "");
        int row = 0, step = 1;
        for(int i = 0; i < len; i++)
        {
            str[row].push_back(s[i]);
            if(row == 0)
                step = 1;
            else if(row == (numRows - 1))
                step = -1;
            row += step;
        }
        
        string result;
        for(int i = 0; i < numRows; i++)
        {
            result.append(str[i]);
        }

        return result;
        
    }
