class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int left = 0, product = 1, res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            while(product >= k)
            {
                product /= nums[left];
                left++;
            }
            
            res += i - left + 1;
        }
        
        return res;
        
    }
};



/*双指针，一开始想的o(n^2)的算法，主要是想要指针往回退，其实是完全没有必要的。最重要的是理解 res += i - left + 1 这一行
*/
