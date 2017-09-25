    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
        
        result.push_back("");
        static const vector<string> alphabet = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for(int i = 0; i < digits.size(); i++)
        {
            int num = int(digits[i] - '0');
            
            if(num < 0 || num > 9) break;
            string current = alphabet[num];
            if(current.empty()) continue;
            
            vector<string> tmp;
            for(int j = 0; j < result.size(); j++)
                for(int k = 0; k < current.size(); k++)
                {
                    tmp.push_back(result[j] + current[k]);
                }
            swap(result,tmp);
        }
        return result;
    }
