    void mycombine(vector<vector<int>>& result, vector<int>& candidates, vector<int>& tmp, int target, int s)
    {
        if(target == 0)
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i = s; (i < candidates.size()) && (target >= candidates[i]); i++)
        {

            if(i && i > s && candidates[i] == candidates[i - 1])
                continue;
            tmp.push_back(candidates[i]);
            mycombine(result, candidates, tmp, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> tmp;
        mycombine(result, candidates, tmp, target, 0);
        return result;      
    }



