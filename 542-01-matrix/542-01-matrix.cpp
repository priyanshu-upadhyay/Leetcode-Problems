class Solution {
private:
    vector<pair<int, int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1)
                {
                    result[i][j] = -1;
                }
                else
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            pair<int, int> front = q.front();
            q.pop();
            for(pair<int, int> dir : dirs)
            {
                int iDash = dir.first + front.first;
                int jDash = dir.second + front.second;
                if(iDash >= 0 && iDash < n && jDash >= 0 && jDash < m && result[iDash][jDash] < 0)
                {
                    result[iDash][jDash] = 1 + result[front.first][front.second];
                    q.push({iDash, jDash});
                }
                
            }
        }
        
        return result;
    }
};