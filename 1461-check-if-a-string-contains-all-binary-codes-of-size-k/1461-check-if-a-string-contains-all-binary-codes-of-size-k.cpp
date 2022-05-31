class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> result;
        int total = pow(2, k);
        int n = s.length();
        
        string st = "";
        for(int i = 0; i < min(k,n); i++)
        {
            st = st + s[i];
        }
        result.insert(st);
        for(int i = k; i < n; i++)
        {
            st.erase(st.begin());
            st = st + s[i];
            result.insert(st);
        }
        return result.size() == total;
    }
};