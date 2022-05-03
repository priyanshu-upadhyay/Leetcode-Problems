class Solution {
public:
    bool isValid(string s) {
        //  Jab bhi koi aage wali chiz peeche depend kar rhi ho to samjhlo....... Stack hai bhaiya....
        
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char top = st.top();
                if(s[i] == ')' && top == '(') 
                {
                    st.pop();
                }
                else if(s[i] == ']' && top == '[')
                {
                    st.pop();
                }
                else if(s[i] == '}' && top == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
        
    }
};