class Solution {
private:
    vector<pair<int, int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfsCheckBoundary(int i, int j, int n, int m, vector<vector<int>>& grid, bool &check, int& c)
    {
        if(i < 0 || j < 0 || i >= n || j >= m)
        {
            check = false;
            return;
        }
        if(grid[i][j] == 1)
        {
            c++;
            grid[i][j] = 0;
            for(pair<int, int> dir : dirs)
            {
                int new_i = dir.first;
                int new_j = dir.second;
                dfsCheckBoundary(i + new_i, j + new_j, n, m, grid, check, c);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                bool check = true;
                int c = 0;
                if(grid[i][j] == 1)
                {
                    dfsCheckBoundary(i, j, n, m, grid, check, c);
                    if(check)
                    {
                        count += c;
                    }
                }
            }
        }
        return count;
    }
};