    int divide(int dividend, int divisor) {
        if((divisor == 0) || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend > 0) ^ (divisor > 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while(dvd >= dvs)
        {
            long long tmp = dvs, multiple = 1;
            while(dvd >= (tmp << 1))
            {
                tmp = tmp << 1;
                multiple = multiple << 1;
            }
            res += multiple;
            dvd -= tmp;
        }
        return sign == 1 ? res : -res;
    }
/*二分查找
除数一直左移，直到除数大于被除数为止，然后用被除数减去移位运算后的除数，作为新一轮迭代的对象。
*/
