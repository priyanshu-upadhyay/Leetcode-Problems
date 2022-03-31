class Solution {
public:
    
    bool isPossible(vector<int>& nums, int m, int sum)
    {
        int sumTillPoint = 0, countSubArray = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(sumTillPoint + nums[i] <= sum)
            {
                sumTillPoint += nums[i];
            }
            else
            {
                countSubArray++;
                if(countSubArray > m || nums[i] > sum)
                {
                    return false;
                }
                sumTillPoint = nums[i];
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end()), high = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(isPossible(nums, m, mid))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return result;
    }
};