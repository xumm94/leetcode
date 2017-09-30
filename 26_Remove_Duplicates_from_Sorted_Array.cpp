    int removeDuplicates(vector<int>& nums) {

        if((nums.end()-nums.begin())==0)

        return 0;

        auto first=nums.begin();

        auto second=nums.begin()+1;

        int i=0;

      while(second!=nums.end())

      {

          if(*first==*second)

            i++;

          else

           {

               ++first;

                *first=*second;

           }

            second++;

      }

      return nums.end()-nums.begin()-i;

    }


