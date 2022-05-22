class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int c = 0;
        for(int gap = 0; gap < n; gap++)
        {
            for(int i = 0, j = gap; j < n; j++, i++)
            {
                
                if(gap == 0)
                {
                    dp[i][j] = true;
                }
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                }
                else
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] == true) c++;
            }
        }
        
        return c;
        
    }
};