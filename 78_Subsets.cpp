    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result(1,vector<int>());

       if(nums.empty())

       return result;

       sort(nums.begin(), nums.end());

       for(int i = 0; i < nums.size(); i++)

       {

           int n = result.size();

           for(int j = 0; j < n; j++)

           {

               result.push_back(result[j]);

               result.back().push_back(nums[i]);

           }

       }

       return result;

    }
