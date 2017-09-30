    int removeElement(vector<int>& nums, int val) {

        if(!nums.size()) return 0;

        bool exist = 0;

        for(int i = 0; i < nums.size();i++)

        {

            if(nums[i] == val)

            {

                exist = 1;

                break;

            }

        }

        if(!exist) return nums.size();

      auto ptr_1 = nums.begin();

      auto ptr_2 = nums.end() - 1;

      while(ptr_2 > ptr_1)

      {

          if(*ptr_1 == val)

          {

              while(*ptr_2 == val)

              {

                  ptr_2--;

              }

              if(ptr_2 <= ptr_1)

              break;

              *ptr_1 = *ptr_2;

              *ptr_2 = val;

          }

          ptr_1++;

          

      }

      ptr_1 = nums.begin();

      while(*ptr_1 != val)

      ptr_1++;

      return ptr_1 - nums.begin();

        

    }
