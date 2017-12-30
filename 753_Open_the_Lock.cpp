class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead_end(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> bfs;
        string init = "0000";
        if(init == target)
            return 0;
        if(dead_end.find(target) != dead_end.end() || dead_end.find(init) != dead_end.end())
            return -1;
        visited.insert(init);
        bfs.push(init);
        int res = 0;
        
        while(!bfs.empty())
        {
            int queue_size = bfs.size();
            for(int i = 0; i < queue_size; i++)
            {
                string curr = bfs.front();
                bfs.pop();
                vector<string> nbrs = move(nbrStrs(curr));
                for(auto &s : nbrs)
                {
                    if(s == target)
                        return ++res;
                    
                    if(visited.find(s) != visited.end())
                        continue;
                    
                    if(dead_end.find(s) == dead_end.end())
                    {
                        bfs.push(s);
                        visited.insert(s);
                    }
                }
                
            }
            res++;
        }
        
        return -1;
    }
    
    vector<string> nbrStrs(string key) {
        vector<string> res;
        for (int i = 0 ; i < 4; i++) {
            string tmp = key;
            tmp[i] = (key[i] - '0' + 1) % 10 + '0';
            res.push_back(tmp);
            tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(tmp);
         }
        return res;
    }
};

/*典型的广度优先搜索，需要考虑的是nbrStrs函数怎么写
另外，看到一个比较新的函数，move，是C++11的标准，需注意*/
