    int searchInsert(vector<int>& nums, int target) {

        if(!nums.size()) return 0;

        auto ptr_1 = nums.begin();

        while((ptr_1 != nums.end()) && (*ptr_1 <= target))

        {

            if(*ptr_1 == target)

            return ptr_1 - nums.begin();

            ptr_1++;

        }

        if(ptr_1 == nums.end())

            return nums.size();

        if(ptr_1 == nums.begin())

        return 0;

        

            return ptr_1 - nums.begin()  ;

    }


/*线性时间复杂度也通过了，但是可以达到对数复杂度，和第34题相同*/
