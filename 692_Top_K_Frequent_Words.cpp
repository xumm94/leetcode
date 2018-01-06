class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, pair<string, int>> hash_map;
        for(auto &s : words)
        {
            if(hash_map.count(s) == 0)
            {
                pair<string ,int > p1= make_pair(s,0);
                hash_map[s] = p1;
            }
            hash_map[s].second++;
        }
        
        vector<pair<string,int>> s_count_list;
        for(auto ptr = hash_map.begin(); ptr != hash_map.end(); ptr++)
            s_count_list.push_back(ptr->second);
        
        sort(s_count_list.begin(), s_count_list.end(), compare);
        
        vector<string> result;
        for(int i = k, j = 0; i > 0 && j < s_count_list.size(); i--, j++)
            result.push_back(s_count_list[j].first);
        return result;
    }

    static inline bool compare(pair<string,int> &lhs, pair<string, int> &rhs)
    {
        if(lhs.second == rhs.second)
            return lhs.first < rhs.first;
        
        return lhs.second > rhs.second;
    }
};
