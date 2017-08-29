bool canJump(vector<int>& nums) {
        int far = 0;
        for(int reach = 0; far < nums.size() && far <= reach; far++)
            reach = max(far + nums[far], reach);
        return far >= nums.size();
    }
/*
每走一步，看看最远能走到那
*/
