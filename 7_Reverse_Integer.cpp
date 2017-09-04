    int reverse(int x) {
        if(x == 0)
            return 0;
        bool flag = x > 0 ? 1 : 0;
        
        long tmp = abs(x);
        long result = 0;
        while(tmp > 0)
        {
            result = result * 10 + tmp % 10;
            tmp /= 10;
        }
        if(!flag)
            result = -result;
        if((result <  -2147483648) || (result >  2147483647))
            return 0;
        return result;
        
    }
