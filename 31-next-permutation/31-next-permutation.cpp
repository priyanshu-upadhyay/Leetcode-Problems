class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), break_index;
        
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                break_index = i;
                break;
            }
        }
        
        if(break_index < 0)   //  That means koi break point nhi pura mamla he reverse kro
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int next_greater;
            for(int i = n - 1; i >= 0; i--)
            {
                if(nums[i] > nums[break_index])
                {
                    next_greater = i;
                    break;
                }
                
            }
            swap(nums[next_greater], nums[break_index]);
            reverse(nums.begin() + break_index + 1, nums.end());
        }
    }
};