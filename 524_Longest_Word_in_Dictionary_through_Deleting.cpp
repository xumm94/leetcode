class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(auto &tar: d)
        {
            size_t s_index = 0, tar_index = 0;
            for(; s_index < s.size() && tar_index < tar.size(); s_index++)
            {
                if(s[s_index] == tar[tar_index])
                    tar_index++;
            }
            
            if(tar_index != tar.size())
                continue;
            if(tar.size() >= res.size())
            {
                if(tar.size() > res.size() || tar < res)
                    res = tar;
            }

        }
        return res;
    }
};




/*注意一下最后的判断条件，一开始没有设置第一重的if语句，也就是
没有tar.size() >= res.size()这一句。
题目要求字典序最小，所以第二重if中有判断字典序，如果没有第一重循环，会出现错误*/i
