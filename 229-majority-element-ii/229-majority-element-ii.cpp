class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(num1 == nums[i])
            {
                count1++;
            }
            else if(num2 == nums[i])
            {
                count2++;
            }
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        // checking possible or not
        
        int minCount = n/3, c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(num1 == nums[i])
            {
                c1++;
            }
            else if(num2 == nums[i])
            {
                c2++;
            }
        }
        
        vector<int> result;
        
        if(c1 > minCount)
        {
            result.push_back(num1);
        }
        if(c2 > minCount)
        {
            result.push_back(num2);
        }
        
        return result;
        
    }
};