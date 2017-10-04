    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> result;

        auto it1=nums1.begin();

        auto it2=nums2.begin();

        int size_num1=0;

        int size_num2=0;

        

        while((size_num1<m)&&(size_num2<n))

        {

            if(nums1[size_num1]<=nums2[size_num2])

            {

                result.push_back(nums1[size_num1]);

                size_num1++;

            }

            else

            {

                result.push_back(nums2[size_num2]);

                size_num2++;

            }

        }

        

        while(size_num1<m)

         {

            result.push_back(nums1[size_num1]);

            size_num1++;

         }

         while(size_num2<n)

         {

            result.push_back(nums2[size_num2]);

            size_num2++;

         }

         nums1=result;

    }
