vector<int> twoSum(vector<int>& nums, int target) {

        auto first=nums.begin();

        auto second=first+1;

        vector<int> result;

        while(first<nums.end())

        {

            second=first+1;

            while(second<nums.end())

            {

                if((*first+*second)==target)

                {

                    result.push_back(first-nums.begin());

                     result.push_back(second-nums.begin());

                }

                second++;

            }

            first++;

        }

        return result;

        

    }
