class Solution {
private:

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(), intervals.end());
        for(vector<int> each_interval : intervals)
        {
            if(!st.empty())
            {
                vector<int> top = st.top();
                if(top[1] >= each_interval[0])
                {
                    st.pop();
                    top[1] = max(each_interval[1], top[1]);
                    st.push(top);
                }
                else
                {
                    st.push(each_interval);
                }
            }
            else
            {
                st.push(each_interval);
            }
        }
        
        vector<vector<int>> result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};