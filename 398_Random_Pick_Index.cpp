class Solution {
public:
    Solution(vector<int> nums) {
    _nums = nums;
        
    }
    
    int pick(int target) {
        int ans = -1, n = 0;
        for(int i = 0; i < _nums.size(); i++)
        {
            if(_nums[i] == target)
            {
                if(n == 0)
                {
                    ans = i;
                    n++;
                }
                else
                {
                    n++;
                    if(rand() % n == 0)
                         ans = i;                    
                }
            }
        }
        
        return ans;
        
    }
private:
    vector<int> _nums;
};

