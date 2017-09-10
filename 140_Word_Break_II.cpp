    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev)
    {
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(m.count(s))
            return m[s];
        vector<string> res;
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
            res.push_back(s);
        for(int i = 1; i < s.size(); i++)
        {
            string word = s.substr(i);
            if(find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
            {
                string rem = s.substr(0,i);
                vector<string> pre = combine(word, wordBreak(rem, wordDict));
                res.insert(res.end(), pre.begin(), pre.end());
            }
          
        }
        m[s] = res;
        return res;
            
        
    }
/*substr的两种用法，假设s = "0123456789"
s.substr(5) = "56789"
s.substr(0,5) = "01234"

*/
