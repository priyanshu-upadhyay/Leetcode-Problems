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
        // Defining Start and End of Each Block;
        int redStart = 0, redEnd = red;
        int whiteStart = redEnd, whiteEnd = redEnd + white;
        int blueStart = whiteEnd, blueEnd = whiteEnd + blue;
        
        // cout<<redStart<<" "<<redEnd<<"\n";
        // cout<<whiteStart<<" "<<whiteEnd<<"\n";
        // cout<<blueStart<<" "<<blueEnd<<"\n";
        int i = 0;
        
        while(i < n)
        {
            if(nums[i] == 0 && redStart < redEnd)
            {
                swap(nums[i], nums[redStart++]);
            }
            else if(nums[i] == 1 && whiteStart < whiteEnd)
            {
                swap(nums[i], nums[whiteStart++]);
            }
            else if(nums[i] == 2 && blueStart < blueEnd)
            {
                swap(nums[i], nums[blueStart++]);
            }
            else
            {
                i++;
            }
        }
    }
};