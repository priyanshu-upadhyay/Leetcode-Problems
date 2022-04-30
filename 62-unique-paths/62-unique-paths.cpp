class Solution {
private:
    int dp[101][101];
    
public:
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        if(m > 0 && n > 0)
        {
            if(dp[m][n] != -1) return dp[m][n];
            int a = uniquePaths(m - 1, n);
            int b = uniquePaths(m, n - 1);
            int sum = 0;
            if(a >= 0)
            {
                sum += a;
            }
            if(b >= 0)
            {
                sum += b;
            }
            return dp[m][n] = sum;
        }
        return -1;
    }
};