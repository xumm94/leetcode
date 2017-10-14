    int titleToNumber(string s) {

        int sum = 0;

        int mul = 1;

        for(int i = s.size() - 1; i >=0; i--)

        {

            sum += mul * int(s[i] - 64);

            mul *= 26;

        }

        return sum;

    }
