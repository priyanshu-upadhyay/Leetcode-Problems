class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        string orginal_s = "", orignal_t = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(!st.empty())
            {
                if(s[i] == '#') st.pop();
                else st.push(s[i]);
            }
            else
            {
                if(s[i] != '#') st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            orginal_s = st.top() + orginal_s;
            st.pop();
        }
        
        for(int i = 0; i < t.length(); i++)
        {
            if(!st.empty())
            {
                if(t[i] == '#') st.pop();
                else st.push(t[i]);
            }
            else
            {
                if(t[i] != '#') st.push(t[i]);
            }
        }
        while(!st.empty())
        {
            orignal_t = st.top() + orignal_t;
            st.pop();
        }
        cout<<orginal_s<<" : "<<orignal_t<<"\n";
        return orignal_t == orginal_s;
        
    }
};