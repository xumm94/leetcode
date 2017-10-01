    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<vector<int>> use1(9, vector<int>(9, 0)), use2(9, vector<int>(9, 0)), use3(9, vector<int>(9, 0));
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1', k = i / 3 * 3 + j / 3;
                if(use1[i][num] || use2[j][num] || use3[k][num])
                    return false;
                use1[i][num] = use2[j][num] = use3[k][num] = 1;
            }
        }
        return 1;
        
    }
