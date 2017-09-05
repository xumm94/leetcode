    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> hash_map;
        vector<int> result(findNums.size(), 0);
        stack<int> s;
        
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!s.empty() && s.top() < nums[i])
                s.pop();
            hash_map[nums[i]] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        
        for(int i = 0; i < findNums.size(); i++)
        {
            result[i] = hash_map[findNums[i]];
        }
        return result;
    }


/*从后向前遍历，利用栈记录遍历过的值。
假设当前的值为nums[i]，栈中的数全部是i后面的。
将nums[i]与s.top()比较，如果nums[i] > s.top()则一直出站
如果s是空的，那么不存在下一个大于nums[i]的数，否则，s.top()就是要求解的值*/

