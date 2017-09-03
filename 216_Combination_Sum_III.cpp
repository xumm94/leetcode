    void mycombine(vector<vector<int>> &result, vector<int> &tmp, int k, int n)
    {
        
        if(k == 0)
        {
            if(n == 0)
                result.push_back(tmp);
            return;
        }
        
        for(int i = (tmp.empty() ? 1 : tmp.back() + 1); i <= 9 ; i++)
        {    
            if(n - i < 0)
                break;
            tmp.push_back(i);
            mycombine(result, tmp, k - 1, n - i);
            tmp.pop_back();
            
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> tmp;
        mycombine(result, tmp, k, n);
        return result;
        
    }
