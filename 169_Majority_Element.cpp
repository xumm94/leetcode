    int majorityElement(vector<int>& nums) {

        map<int,int> count;

        for(int i = 0; i < nums.size(); i++)

        {

            count[nums[i]] = 0;

        }

        for(int i = 0; i < nums.size(); i++)

        {

            count[nums[i]]++;

        }

        int max = 0;

        int result = 0;

        for(auto ptr = count.begin(); ptr != count.end(); ptr++)

        {

            if(ptr->second > max)

            {

                max = ptr->second;

                result = ptr->first;

            }

        }

        return result;

        

    }
