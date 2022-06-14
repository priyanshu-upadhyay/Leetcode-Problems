class Solution {
    private:
        int dp[501][501];
    int longestCommonSubSequenece(string word1, string word2, int n, int m)
    {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(word1[n-1] == word2[m-1])
        {
            return dp[n][m] = 1 + longestCommonSubSequenece(word1, word2, n-1, m-1);
        }
        return dp[n][m] = max(longestCommonSubSequenece(word1, word2, n-1, m), longestCommonSubSequenece(word1, word2, n, m-1));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length(), m = word2.length();
        memset(dp, -1, sizeof(dp));
        int common = longestCommonSubSequenece(word1, word2, n, m);
        int result = (n + m) - 2*common;
        return result;
    }
};