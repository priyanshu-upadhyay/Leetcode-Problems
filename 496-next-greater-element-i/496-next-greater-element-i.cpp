class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        unordered_map<int, int> pos;
        vector<int> nextGreater(n, -1);
        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            if(!st.empty())
            {
                nextGreater[i] = st.top();
            }
            st.push(nums2[i]);
            
            pos[nums2[i]] = i;
        }
        int m = nums1.size();
        vector<int> answer(m);
        for(int i = 0; i < m; i++)
        {
            answer[i] = nextGreater[pos[nums1[i]]];
        }
        return answer;
        
    }
};