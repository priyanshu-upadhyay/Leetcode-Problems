class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        string result = "";
        for(int g = 0; g < n; g++)
        {
            for(int i = 0, j = g; j < n; i++, j++)
            {
                if(g == 0)
                {
                    dp[i][j] = true;
                }
                else if(g == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if(s[i] == s[j] && dp[i+1][j-1] == true)
                    {
                        dp[i][j] = true;
                    }
                }
                
                if(dp[i][j] == true)
                {
                    result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};