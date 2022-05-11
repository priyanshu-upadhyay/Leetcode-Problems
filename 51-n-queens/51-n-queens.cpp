class Solution {
private:
    
    bool checkCanWePlace(int n, int row, int col, vector<string> board)
    {
        /*
            checking in 3 directions
            1.  row - 1, col - 1
            2.  row - 1, col
            3.  row - 1, col + 1
        */
        
        // checking for (1) condition
        
        int row1 = row, col1 = col;
        while(row1 >= 0 && col1 >= 0)
        {
            if(board[row1][col1] == 'Q')
            {
                return false;
            }
            row1--;
            col1--;
        }
        
        
        int row2 = row, col2 = col;
        while(row2 >= 0)
        {
            if(board[row2][col2] == 'Q')
            {
                return false;
            }
            row2--;
        }
        
        int row3 = row, col3 = col;
        while(row3 >= 0 && col3 < n)
        {
            if(board[row3][col3] == 'Q')
            {
                return false;
            }
            row3--;
            col3++;
        }
        
        return true;
        
    }
    
    void solveNQueensHelper(int n, int row, vector<string>& board, vector<vector<string>>& result)
    {
        if(row == n)
        {
            result.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++)
        {
            if(checkCanWePlace(n, row, col, board))
            {
                board[row][col] = 'Q';
                solveNQueensHelper(n, row + 1, board, result);
                board[row][col] = '.';  
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solveNQueensHelper(n, 0, board, result);
        return result;
        
    }
};