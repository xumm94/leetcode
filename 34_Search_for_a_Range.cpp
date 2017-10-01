    inline int binsearch(vector<int>& nums, int start, int end, int target)
    {
        if(start > end)
            return -1;
        if(start == end)
        {
            if(nums[start] == target)
                return start;
            else
                return -1;
        }
        
        int mid = mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target)
            return binsearch(nums,start,mid,target);
        else
            return binsearch(nums,mid + 1,end,target);
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.empty())
            return result;
        
        int start = 0;
        int end = nums.size() - 1;
        int mid= binsearch(nums,start,end,target);
        if(mid == -1)
            return result;
        int mid_front = mid;
        int mid_back = mid;
        int mid_back_old = mid;
        int mid_front_old = mid;
        
        
        while((mid_front >= 0) && (mid_front <= nums.size()) && (nums[mid_front] == target))
        {
            mid_front_old = mid_front;
            mid_front = binsearch(nums,start,mid_front - 1,target);
        }

        while(nums[mid_front_old] != target)
            mid_front++;
        while((mid_back >= 0) && (mid_back <= nums.size()) && (nums[mid_back] == target))
        {   
            mid_back_old = mid_back;
            mid_back = binsearch(nums,mid_back + 1,end,target);
        }
        while(nums[mid_back_old] != target)
            mid_back_old--;
        
        result[0] = mid_front_old;
        result[1] = mid_back_old;
        return result;
        
    }

/*考察二分查找，注意命中第一个元素以后，可以继续在前面和后面递归二分查找，而不是靠向前向后一个个找*/
