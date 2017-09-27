    inline int gcd(int m, int n)
    {
        if(n == 0)
            return m;
        else
            return gcd(n, m % n);
    }
    bool canMeasureWater(int x, int y, int z) {
        int m = max(x, y);
        int n = min(x, y);
        if(x + y < z)
            return 0;
        if(z == m || z == n || z == 0)
            return 1;
        if(x == 0 || y == 0)
            return z == x || z == y;
        int num = gcd(m, n);
        if(z % num == 0)
            return 1;
        else
            return 0;
    }
/*此题牵扯到一定的数论知识。当z能整除gcd(x,y)时，可以凑出z的水*/
