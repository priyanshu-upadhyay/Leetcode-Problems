class Solution {
private:
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{-1,1},{1,-1},{-1,-1},{1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 0});
        grid[0][0] = 1;
        while(!q.empty())
        {
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            int i = front.first.first, j = front.first.second;
            int dis = front.second;
            if(i == n - 1 && j == n - 1) return dis + 1;
            for(pair<int, int> each : dirs)
            {
                int iDash = i + each.first;
                int jDash = j + each.second;
                if(iDash >= 0 && jDash >= 0 && iDash < n && jDash < n && grid[iDash][jDash] == 0)
                {
                    grid[iDash][jDash] = 1;
                    q.push({{iDash,jDash}, dis + 1});
                }
            }
        }
        return -1;
    }
};