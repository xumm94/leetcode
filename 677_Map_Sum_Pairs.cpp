class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        dict[key] = val;
        
    }
    
    int sum(string prefix) {
        int sum = 0;
        int n = prefix.size();
        for(auto it = dict.lower_bound(prefix); it != dict.end() && it->first.substr(0, n) == prefix; it++)
            sum += it->second;
        
        return sum;
        
    }
    
private:
    map<string , int> dict;
    
};

/*注意lower_bound的用法，对于map来说，其两个成员名我first和second*/
