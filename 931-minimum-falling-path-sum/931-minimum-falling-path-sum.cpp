class Solution {
private:
    int dp[500][500];
public:
    int minSumRec(vector<vector<int>>& matrix, int i, int j, int n, int m)
    {
        if(i == n) return 0; // Last Row me chale gye
        if(i >= 0 && i < n && j >= 0 && j < m)
        {
            if(dp[i][j] != -1) return dp[i][j];
            
            int down = minSumRec(matrix, i+1, j, n, m);
            int rightDiagnol = minSumRec(matrix, i+1, j+1, n, m);
            int leftDiagnol = minSumRec(matrix, i+1, j-1, n, m);
            
            return dp[i][j] = matrix[i][j] + min(down, min(rightDiagnol, leftDiagnol));
        }
        return INT_MAX;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        
        int result = INT_MAX;
        
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < m; i++)
        {  
            result = min(result, minSumRec(matrix, 0, i, n, m));
        } 
        return result;
    }
};