bool found(vector<vector<char>>& board, string& word, int index, int row, int col, vector<vector<bool>>& visited)
    {
        if(index == word.size())
            return true;
        if(visited[row][col] || board[row][col] != word[index])
            return false;
        visited[row][col] = 1;
        for(int i = max(0, row - 1); i <= min(int(board.size()) - 1, row + 1); i++)
            if(found(board, word, index + 1, i, col, visited))
                return true;
        for(int j = max(0, col - 1); j <= min(int (board[0].size()) - 1, col + 1); j++)
            if(found(board, word, index + 1, row, j, visited))
                return true;

        visited[row][col] = 0;
        return false;
    }





    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return word.empty() ? 1 : 0;
        size_t row = board.size();
        size_t col = board[0].size();
        if(col == 0) 
            return word.empty() ? 1 : 0;
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(size_t i = 0; i < row; i++)
        {
            for(size_t j = 0; j < col; j++)
            {
                if(found(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }


/*考察深度优先搜索，注意边界条件。*/
