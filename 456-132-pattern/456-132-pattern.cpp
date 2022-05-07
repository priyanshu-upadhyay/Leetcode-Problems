class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(third > nums[i]) return true;
            while(!st.empty() && st.top() < nums[i])
            {
                third = max(third, st.top());
                st.pop();
            }
            st.push(nums[i]);
        }
        
        return false;
    }
};