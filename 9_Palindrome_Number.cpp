    bool isPalindrome(int x) {
        if(x < 0 || ((x != 0) && (x % 10 == 0)))
            return 0;
        int sum = 0;
        int x_copy = x;
        while(x_copy > sum)
        {
            sum = sum * 10 + x_copy % 10;
            x_copy /= 10;
        }
        if((x_copy == sum) || (sum / 10 == x_copy))
            return 1;
        return 0;
    }
