class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = k, cnt = 0;
        stack<int> nums;
        for(auto &s : num)
        {
            while(!nums.empty() && n > 0 && s < nums.top())
            {
                n--;
                nums.pop();
            }
            
            nums.push(s);
        }
        
        string res = "";
        while(!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        
        reverse(res.begin(), res.end());
        
        while(res[cnt] == '0')
            cnt++;
        
        res = res.substr(cnt, num.size()-k-cnt);
        if(res.size() == 0)
            return "0";
        else 
            return res;
        
    }
};

/*考察贪心算法和栈。希望这串字符串能够维持一个升序。当允许继续删除，并且当前的数字比栈顶小的时候，出栈，计数器减一，并将当前数字压入栈中。
最后，需要考虑排除前面是零的情况
*/
