    int lengthOfLastWord(string s) {

        if(s.empty()) return 0;

        int result = 0;

        int i ;

        for( i = s.size() - 1; i >= 0; i--)

        {

            if(s[i] != ' ')

            break;

        }

        for(;i >= 0; i--)

        {

            if(s[i] != ' ')

            result++;

            else

            break;

        }

        return result;

    }
