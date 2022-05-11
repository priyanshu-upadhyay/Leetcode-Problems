class Solution {
private:
    int dp[21][10001];
    int coinChangeHelper(vector<int>& coins, int n, int amount)
    {
        if(amount == 0) return 0;
        if(n == 0) return INT_MAX - 1;
        if(dp[n][amount] != -1) return dp[n][amount];
        if(amount - coins[n-1] >= 0)
        {
            return dp[n][amount] = min( 1 + coinChangeHelper(coins, n, amount - coins[n-1]), coinChangeHelper(coins, n - 1, amount));
        }
        return dp[n][amount] = coinChangeHelper(coins, n - 1, amount);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int result = coinChangeHelper(coins, coins.size(), amount);
        if(result == INT_MAX || result == INT_MAX - 1) return -1;
        return result;
    }
};