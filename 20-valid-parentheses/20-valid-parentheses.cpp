class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    char ch = st.top();
                    if(s[i] == ')' && ch == '(')
                    {
                        st.pop();
                    }
                    else if(s[i] == '}' && ch == '{')
                    {
                        st.pop();
                    }
                    else if(s[i] == ']' && ch == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        return st.empty();
    }
};