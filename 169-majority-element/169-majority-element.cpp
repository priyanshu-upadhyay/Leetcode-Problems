class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num, c = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(c == 0)
            {
                num = nums[i];
                c++;
            }
            else if(num == nums[i])
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return num;
    }
};