class Solution {
    
private:
    int dp[101][101];
    int countPaths(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid)
    {
        if(i < 0 || j < 0 || i >= n || j >= m || obstacleGrid[i][j] == 1) return 0;
        if(i == n - 1 && j == m - 1) return 1;
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = countPaths(i + 1, j, n, m, obstacleGrid);
        int left = countPaths(i, j + 1, n, m, obstacleGrid);
        dp[i][j] = right + left;
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return countPaths(0, 0, n, m, obstacleGrid);
    }
};