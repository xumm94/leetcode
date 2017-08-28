    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int imax = m, imin = 0,  half_len = (m + n + 1) / 2;
        while(imin <= imax)
        {
            int i = (imin + imax) / 2;
            int j = half_len - i;
            
            if((i > 0 && j < n) && nums1[i - 1] > nums2[j])
                imax--;
            else if( i < m && j > 0 && nums2[j - 1] > nums1[i])
                imin++;
            else
            {
               double max_left;
                if(i == 0)
                    max_left = nums2[j - 1];
                else if(j == 0) 
                        max_left = nums1[i - 1];
                else
                    max_left = max(nums1[i - 1], nums2[j - 1]);
               
                if((m + n) % 2 == 1)
                    return max_left;
                
                double min_right;
                if(i == m)
                    min_right = nums2[j];
                else if(j == n)
                    min_right = nums1[i];
                else 
                    min_right = min(nums1[i], nums2[j]);
                
                return (max_left + min_right) / 2;
                    
                    
            }
        }    
    }
