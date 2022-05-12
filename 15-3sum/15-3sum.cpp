class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; )
        {
            int j = i + 1,  k = n - 1;
            while(j < k)
            {
                
                if(nums[j] + nums[k] > -1 * nums[i])
                {
                    k--;
                }
                else if(nums[j] + nums[k] < -1 * nums[i])
                {
                    j++;
                }
                else
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while(j < k && nums[j-1] == nums[j]) j++;
                    while(j < k && nums[k+1] == nums[k]) k--;
                }
            }
            i++;
            while(i < n && nums[i-1] == nums[i]) i++;
            
        }
        return result;
    }
};