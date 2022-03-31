class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int longestSeq = 0;
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
            longestSeq = max(dp[i], longestSeq); //  ab tak ka sabse bada sequence
        }
        return longestSeq;
    }
};