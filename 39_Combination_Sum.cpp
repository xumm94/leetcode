    void mycom(vector<vector<int>>& result, vector<int>& candidates, vector<int>& tmp, int target, int begin)
    {
        if(target == 0)
        {
            result.push_back(tmp);
            return;
        }
        
        for(int i = begin; (i < candidates.size()) && (target >= candidates[i]); i++)
        {
            tmp.push_back(candidates[i]);
            mycom(result, candidates, tmp, target - candidates[i], i);
            tmp.pop_back();
        }
            
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty())
            return result;
        
        sort(candidates.begin(), candidates.end());
        vector<int> tmp;
        mycom(result, candidates, tmp, target, 0);
        return result;
        
        
    }

//回溯法，注意vector还有一个pop_back()的方法可以调用
