class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int result = 0;
        
        int curr = 0, n = nums.size();
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            if(st.find(nums[i]) == st.end())
            {
                curr += nums[i];
                result = max(result, curr);
                st.insert(nums[i]);
                i++;
            }
            else
            {
                curr -= nums[j];
                st.erase(nums[j]);
                j++;
            }
            
        }
        return result;
    }
};