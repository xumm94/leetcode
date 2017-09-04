    int myAtoi(string str) {
        if(str.empty())
            return 0;
        long result = 0;
        int sign = 1;
        
        int index = 0;
        for(;index < str.size(); index++)
        {
            if(str[index] != ' ')
                break;
        }
        
        if((str[index] == '+') || (str[index] == '-'))
            sign = str[index++] == '+' ? 1 : -1;
        

        while((str[index] >= '0') && (str[index] <= '9'))
        {
            result = result * 10 + long(str[index++] - '0');
            if(sign * result > INT_MAX) return INT_MAX;
            if(sign * result < INT_MIN) return INT_MIN;
        }
        return sign * result;
    }
