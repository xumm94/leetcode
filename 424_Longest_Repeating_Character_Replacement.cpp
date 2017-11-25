    int characterReplacement(string s, int k) {
        int res = 0, maxcnt = 0, start = 0;
        vector<int> charcount(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            maxcnt = max(maxcnt, ++charcount[s[i] - 'A']);
            while( i - start + 1 - maxcnt > k)
            {
                charcount[s[start] - 'A']--;
                start++;
            }
            res = max(res, i - start + 1);
        }
        
        return res;
        
    }

/*
如果没有k的限制，让我们求把字符串变成只有一个字符重复的字符串需要的最小置换次数，那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k的限制，我们其实就是求满足(子字符串的长度减去出现次数最多的字符个数)<=k的最大子字符串长度即可，搞清了这一点，我们也就应该知道怎么用滑动窗口来解了吧我们用一个变量start记录滑动窗口左边界，初始化为0，然后我们遍历字符串，每次累加出现字符的个数，然后更新出现最多字符的个数，然后我们判断当前滑动窗口是否满足之前说的那个条件，如果不满足，我们就把滑动窗口左边界向右移动一个，并注意去掉的字符要在counts里减一，直到满足条件，我们更新结果res即可。
*/
