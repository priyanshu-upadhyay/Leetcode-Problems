class Solution {
private:
    vector<pair<int, int>> dirs = {{-1,-1},{1,1},{-1,1},{1,-1},{-1,0},{1,0},{0,-1},{0,1}}; // Eight Directions
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int activeCell = 0;
                
                // check all 8 directions
                for(int dir = 0; dir < 8; dir++)
                {
                    int iDash = i + dirs[dir].first;
                    int jDash = j + dirs[dir].second;
                    
                    if(iDash >= 0 && iDash < n  && jDash >= 0  && jDash < m)
                    {
                        if(abs(board[iDash][jDash]) == 1)
                        {
                            activeCell++;
                        }
                    }
                }
                
                if(board[i][j] == 1)
                {
                    if(activeCell < 2)
                    {
                        board[i][j] = -1;
                    }
                    else if(activeCell > 3)
                    {
                        board[i][j] = -1;
                    }
                }
                else
                {
                    if(activeCell == 3)
                    {
                        board[i][j] = 2;
                    }
                }
                
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == -1)
                {
                    board[i][j] = 0;
                }
                if(board[i][j] == 2)
                {
                    board[i][j] = 1;
                }
            }
        }    
    }
};