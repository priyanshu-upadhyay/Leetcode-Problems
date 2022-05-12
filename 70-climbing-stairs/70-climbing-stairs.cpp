class Solution {
private:
    int dp[46];
    int climbHelper(int n)
    {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = climbHelper(n - 1) + climbHelper(n - 2);
    }
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return climbHelper(n);
    }
};