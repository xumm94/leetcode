    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash_table(128, 0);
        for(auto &c : magazine)
            hash_table[c]++;
        for(auto &c : ransomNote)
        {
            if(hash_table[c] == 0)
                return 0;
            else
                hash_table[c]--;
        }
        return 1;
        
    }
