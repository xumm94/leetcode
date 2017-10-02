    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        if(n == 0)
            return result;
        int left_top = 0;
        int right_bot = n - 1;
        int num = 1;
        while(left_top < right_bot)
        {
        
            for(int i = left_top; i <= right_bot; i++)
                result [left_top][i] = num++;
            for(int i = left_top + 1; i <= right_bot; i++)
                result[i][right_bot] = num++;
            for(int i = right_bot - 1; i >= left_top; i--)
                result[right_bot][i] = num++;
            for(int i = right_bot - 1; i >= left_top + 1; i--)
                result[i][left_top] = num++;
            
            left_top++;
            right_bot--;
        }
        if(left_top == right_bot)
            result[right_bot][left_top] = num++;
        
        return result;
    }
