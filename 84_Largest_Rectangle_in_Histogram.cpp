class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;
        stack<int> s;
        for(int i = 0; i <= n; i++)
        {
            int h = i == n ? 0 : heights[i];
            
            if(s.empty() || heights[s.top()] <= h)
            {
                s.push(i);
            }
            else
            {
                int t = s.top();
                s.pop();
                int area = heights[t] * (s.empty() ? i : i - 1 - s.top());
                result = max(area, result);
                i--;
            }
        }
        
        return result;
        
    }
};


/*
首先考虑特殊情况，如果height数组是升序，应该怎么做？
比如1,2,5,7,8
那么就是(1*5) vs. (2*4) vs. (5*3) vs. (7*2) vs. (8*1)

这个问题的核心，就是利用栈来维持一个递增的序列,目前的高度小于栈中顶部的数值的时候，一直出栈，并计算面积。
需要注意的是else语句里面的i--，这一句话起到了一个以及外部的循环起到了一个while的作用，另外，else语句中，当栈为空的时候，表明t元素前面没有比t元素更小的了，所以长度就是i

*/
