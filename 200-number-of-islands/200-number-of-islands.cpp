class Solution {
public:
    void checkIsland(int i, int j, int n, int m, vector<vector<char>>& grid)
    {
        if(i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == '1')
        {
            grid[i][j] = '0';
            checkIsland(i, j+1, n, m, grid);
            checkIsland(i+1, j, n, m, grid);
            checkIsland(i-1, j, n, m, grid);
            checkIsland(i, j-1, n, m, grid);
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int island = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    island++;
                    checkIsland(i, j, n, m, grid);
                }
            }
        }
        return island;
        
    }
};