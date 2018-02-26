class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxl(n);
        vector<int> minr(n);
        
        int tmp = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            tmp = max(nums[i], tmp);
            maxl[i] = tmp;
        }
        
        tmp = INT_MAX;
        for(int j = nums.size() - 1; j >= 0; j--)
        {
            tmp = min(nums[j], tmp);
            minr[j] = tmp;
        }
        int index1 = 0;
        while(index1 < nums.size() && minr[index1] == nums[index1])
            index1++;
        int index2 = nums.size() - 1;
        while(index2 >= index1 && maxl[index2] == nums[index2])
            index2--;
        
        return index2 - index1 + 1;
        
    }
};

/*
维持一个从左向右的升序（maxl）l1，维持一个从右往左的降序（minr）l2，在nums，l1，l2相同的部分取交集，相同的部分就是有序序列
*/
