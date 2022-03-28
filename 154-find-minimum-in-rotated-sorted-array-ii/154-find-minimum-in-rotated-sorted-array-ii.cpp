class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int result = INT_MAX;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            result = min(result, nums[mid]);
            if(nums[mid] == nums[low] && nums[high] == nums[mid])
            {
                low++;
                high--;
                continue;
            }
            if(nums[mid] > nums[high])  //  bada he bhut hai eual wala to upar he save ho jaayega
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};