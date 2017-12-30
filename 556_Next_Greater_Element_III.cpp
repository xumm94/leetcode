class Solution {
public:
    int nextGreaterElement(int n) {
        bool flip = 0;
        string num_str = to_string(n);
        if(num_str.size() == 1)
            return -1;
        char min_num = num_str.back();
        int min_index = num_str.size() - 1;
        int index = num_str.size() - 2;
        for(; index >= 0; index--)
        {   
            if(num_str[index] < num_str[index + 1])
            {
                flip = 1;
                break;
            }
        }
        
        if(!flip)
            return -1;
        
        char c = num_str[index];
        min_num = '9' + 1 + 1;
        min_index = index;
        for(int i = index + 1; i < num_str.size(); i++)
            if(num_str[i] > c)
            {
                if(num_str[i] < min_num)
                {
                    min_index = i;
                    min_num = num_str[i];
                }
            }
        
        swap(num_str[index], num_str[min_index]);
        sort(num_str.begin() + index + 1, num_str.end());
        
        long next = stol(num_str);
        return next > INT_MAX ? -1 : next;
        
    }
};
