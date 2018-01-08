class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; i++)
        {
            if(is_self_Dividing_Number(i))
                result.push_back(i);
        }
        
        return result;
        
    }
    
   inline bool is_self_Dividing_Number(int num)
    {
        int num_copy = num;
        while(num_copy != 0)
        {
            int digit = num_copy % 10;
            if(digit == 0)
                return 0;
            if(num % digit != 0)
                return 0;
            num_copy /= 10;
        }
        
        return 1;
    }
};
