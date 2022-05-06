class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(!st.empty() && st.back().first == s[i])
            {
                if(st.back().second + 1 == k)
                {
                    st.pop_back();
                }
                else
                {
                    st.back().second++;
                }
            }
            else
            {
                st.push_back({s[i], 1});
            }
        }
        string result = "";
        for(auto i : st)
        {
            result.append(i.second, i.first);
        }
        return result;
    }
};