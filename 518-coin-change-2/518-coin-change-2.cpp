class Solution {
private:
    int coinChangeHelper(int n, int amount, vector<int>& coins, vector<vector<int>>& dp)
    {
        if(amount == 0) return 1;
        if(n == 0 || amount < 0) return 0;
        if(dp[n][amount] != -1) return dp[n][amount];
        if(amount >= coins[n-1])
        {
            return dp[n][amount] = coinChangeHelper(n, amount - coins[n-1], coins, dp) +  coinChangeHelper(n - 1, amount, coins, dp);
        }
        return dp[n][amount] = coinChangeHelper(n - 1, amount, coins, dp);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount + 1, -1));
        int result = coinChangeHelper(n, amount, coins, dp);
        return result;
    }
};