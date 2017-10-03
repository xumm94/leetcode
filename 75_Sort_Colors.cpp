    void sortColors(vector<int>& nums) {

        if(!nums.size())

        return;

        int num_red = 0;

        int num_white = 0;

        int num_blue = 0;

        

        auto ptr_1 = nums.begin();

        

        while(ptr_1 != nums.end())

        {

            switch(*ptr_1)

            {

                case 0:

                {

                    num_red++;

                    break;

                }

                 case 1:

                {

                    num_white++;

                    break;

                }

                 case 2:

                {

                    num_blue++;

                    break;

                }

            }

            ptr_1++;

        }

        int i = 0;

        while(num_red != 0)

        {

            nums[i] = 0;

            i++;

            num_red--;

        }

         while(num_white != 0)

        {

            nums[i] = 1;

            i++;

            num_white--;

        }

         while(num_blue != 0)

        {

            nums[i] = 2;

            i++;

            num_blue--;

        }

        

    }
