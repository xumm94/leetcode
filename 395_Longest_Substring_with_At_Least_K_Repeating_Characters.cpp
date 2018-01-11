class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, k, 0, s.size());        
    }
    
    int helper(string &s, int k, int start, int end)
    {
        int len = end - start;
        int max_len = 0;
        if(len <= 0)
            return 0;
        
        vector<int> count(26, 0);
        for(int i = start; i < end;i++)
            count[s[i] - 'a']++;
        
        int pos1 = start, pos2 = start;
        for(; pos2 < end; pos2++)
        {
            if(count[s[pos2] - 'a'] < k)
            {
                max_len = max(max_len, helper(s, k, pos1, pos2));
                pos1 = pos2 + 1;
            }
        }
        
        if(pos1 == start)
            return len;
        else
            return max(max_len, helper(s, k, pos1, pos2));
    }
};

/*分而治之的思想，假设第k个字符在出现的次数小于k，那么可以将字符分割为[0, k-1],
[k-1, s.size()]
*/
