class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        int break_point = - 1;
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] < nums[i + 1])
            {
                break_point = i;
                break;
            }
        }
        
        if(break_point == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int greater_point;
            for(int i = n - 1; i >= 0; i--)
            {
                if(nums[i] > nums[break_point])
                {
                    greater_point = i;
                    break;
                }
            }
            swap(nums[break_point], nums[greater_point]);
            reverse(nums.begin() + break_point + 1, nums.end());
        }
    }
};