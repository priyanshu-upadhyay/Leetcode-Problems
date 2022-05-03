class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1, end = -1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                if(start == -1)
                {
                    start = i - 1;
                    end = i;
                }
                else
                {
                    end = i;
                }
                swap(nums[i-1], nums[i]);
            }
        }
        int start1 = -1, end1 = -1;
        for(int i = nums.size() - 1; i > 0; i--)
        {
            if(nums[i-1] > nums[i])
            {
                if(start1 == -1)
                {
                    start1 = i - 1;
                    end1 = i;
                }
                else
                {
                    start1 = i - 1;
                }
                swap(nums[i-1], nums[i]);
            }
        }
        int newStart;
        if(start1 == -1)
        {
            newStart = start;
        }
        else if(start == -1)
        {
            newStart = start1;
        }
        else
        {
            newStart = min(start, start1);
        }
        
        int newEnd = max(end, end1);
        if(newStart == -1) return 0;
        return newEnd - newStart + 1;
        
    }
};