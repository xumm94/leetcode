    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty())
            return vector<int>();
        size_t word_num = words.size();
        size_t word_size = words[0].size();
        unordered_map<string, int> count;
        if(s.size() < word_num * word_size)
            return vector<int>();
        for(auto &word : words)
            count[word]++;
        vector<int> res;
        
        for(size_t i = 0; i <= s.size() - word_num * word_size; i++)
        {
            unordered_map<string, int> count_sub;
            size_t index = 0;
            for(; index < word_num; index++)
            {
                string word = s.substr(i + index * word_size, word_size);
                if(count.find(word) != count.end())
                {
                    count_sub[word]++;
                    if(count_sub[word] > count[word])
                        break;
                }
                else
                    break;
            }
            if(index == word_num)
                res.push_back(i);
        }
        return res;
    }


/*此题给了一个非常重要的条件，被自己忽略了，单词的长度是相同的*/
