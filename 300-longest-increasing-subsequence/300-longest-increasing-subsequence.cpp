class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for(int i = 0; i < n; i++)
        {
            int maxTillPoint = 0;
            for(int j = i-1; j >= 0; j--)
            {
                if(nums[i] > nums[j])
                maxTillPoint = max(maxTillPoint, dp[j]);
            }
            
            dp[i] = maxTillPoint + 1;
        }
        
        
        int longestSeq = 0;
        
        for(int i = 0; i < n; i++)
        {
            longestSeq = max(dp[i], longestSeq);
        }
        return longestSeq;
    }
};