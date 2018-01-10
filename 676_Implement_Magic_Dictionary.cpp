class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &s : dict)
        {
            size_t s_len = s.size();
            if(hash_map.find(s_len) == hash_map.end())
            {
                vector<string> tmp;
                hash_map[s_len] = tmp;
            }
            
            hash_map[s_len].push_back(s);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        if(hash_map.find(word.size()) == hash_map.end())
            return 0;
        for(auto &s : hash_map[word.size()])
        {
            int diff = 0;
            for(int i = 0; i < word.size(); i++)
            {
                if(word[i] != s[i])
                    diff++;
                if(diff >= 2)
                    break;
            }
            
            if(diff == 1)
                return 1;
        }
        
        return 0;
    }

private:
    unordered_map<size_t, vector<string>> hash_map;
};


/*复习一下unordered_map的一些借口
find()用于判断key是否在哈希表中，
insert()可以向哈希表中插入新的键值对
*/
