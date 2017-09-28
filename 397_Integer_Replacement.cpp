   int integerReplacement(int n) {
        int res = 0;
       long N = n;
        while(N != 1)
        {
            if(N % 2 == 0)
                N = N >> 1;
            else 
            {
                if(N == 3)
                {
                    res += 2;
                    break;
                }
                N = (N & 2) == 2 ? N + 1 : N - 1;
            }
            res++;
        }
        return res;
    }

/*在N = (N & 2) == 2 ? N + 1 : N - 1;这一句出了一些问题，一开始没加括号，运算的结果出了一些问题，应该是优先级的问题。
trick：
如果是偶数，直接除2；
如果是奇数，判断通过加一还是减一可以消除掉最多的1
*/
