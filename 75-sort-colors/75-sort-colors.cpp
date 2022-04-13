class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) red++;
            else if(nums[i] == 1) white++;
            else blue++;
        }
        
        int i = 0;
        for(int j = 0; j < red; j++)
        {
            nums[i++] = 0;
        }
        for(int j = 0; j < white; j++)
        {
            nums[i++] = 1;
        }
        for(int j = 0; j < blue; j++)
        {
            nums[i++] = 2;
        }
    }
};