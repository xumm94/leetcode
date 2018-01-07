class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1001;
        int max2 = -1001;
        int max3 = -1001;
        
        int min1 = 1001;
        int min2 = 1001;
        
        for(auto &num : nums)
        {
            if(num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
            {
                max3 = max2;
                max2 = num;   
            }
            else if(num > max3)
                max3 = num;
            
            if(num < min1)
            {
                min2 = min1;
                min1 = num;
            } 
            else if (num < min2)
                min2 = num;
        }
        
        if(max2 == -1001 || max3 == -1001)
            return max1 * min1 * min2;
        else if(min1 == 1001 || min2 == 1001)
            return max1 * max2 * max3;
        
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
