    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> location;
        set<int> length;
        
        for(int i = 0; i < words.size(); i++)
        {
            location[words[i]] = i;
            length.insert(words[i].size());
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            string s = words[i];
            int len = s.size();
            reverse(s.begin(), s.end());
            
            if(location.count(s) && location[s] != i)
            {
                result.push_back({i, location[s]});
            }
                
                
            auto it_end = length.find(len);
            for(auto it = length.begin(); it != it_end; it++)
            {
                if(isValid(s, 0, len - 1 - *it) && location.count(s.substr(len - *it)))
                    result.push_back({i, location[s.substr(len - *it)]});
                if(isValid(s, *it, len - 1) && location.count(s.substr(0, *it)))
                    result.push_back({location[s.substr(0, *it)], i});
            }
        }
        
        return result;
        
    }
    
    
    bool isValid(string t, int left, int right) 
    {
        while (left < right)
            if (t[left++] != t[right--]) return false;
        return true;
    }
