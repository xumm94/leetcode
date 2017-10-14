    static bool my_string_compare(const string& a, const string& b)
    {
        string ab = a + b;
        string ba = b + a;
        return ab > ba;
    }
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
            return "";
        vector<string> str_vec;
        
        for(int i = 0; i < nums.size();i++)
            str_vec.push_back(to_string(nums[i]));
        
        sort(str_vec.begin(), str_vec.end(), my_string_compare);
        
        string result;
        
        for(int i = 0; i < str_vec.size(); i++)
        {
            result += str_vec[i];
        }
        
        while((result.size() > 1) && (result[0] == '0'))
            result = result.substr(1);
        
        return result;
        
    }


/*将数字按照字典序排序*/
