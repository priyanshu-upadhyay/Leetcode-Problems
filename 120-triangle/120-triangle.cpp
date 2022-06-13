class Solution {
private:
    vector<vector<int>> dp;
    int minSum(vector<vector<int>>& triangle, int row, int col, int n)
    {
        if(row == n) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        
        int step1 = triangle[row][col] + minSum(triangle, row + 1, col, n);
        if(col + 1 < triangle[row].size())
        {
            int step2 = triangle[row][col + 1] + minSum(triangle, row + 1, col + 1,  n);
            return dp[row][col] = min(step1, step2);
        }
        return dp[row][col] = step1;
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        dp.resize(n, vector<int> (m, -1));
        int sum = minSum(triangle, 0, 0, n);
        return sum;
    }
};