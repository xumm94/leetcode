    string convertToTitle(int n) {
        string result;
        int num = n;
        int moshu;
        while(num > 0)
        {
            moshu = (num - 1) % 26 ;

                result += char(moshu + 'A' );

            num = (num - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
