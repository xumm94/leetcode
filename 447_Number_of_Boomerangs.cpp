    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<int, int> count;
            for(int j = 0; j < n; j++)
            {
                int first_dim = points[i].first - points[j].first;
                int second_dim = points[i].second - points[j].second;
                int dis = first_dim * first_dim + second_dim * second_dim;
                count[dis]++;
            }
            
            for(auto it = count.begin(); it != count.end(); it++)
                res += it->second * (it->second - 1);
        }
        
        return res;
        
    }
