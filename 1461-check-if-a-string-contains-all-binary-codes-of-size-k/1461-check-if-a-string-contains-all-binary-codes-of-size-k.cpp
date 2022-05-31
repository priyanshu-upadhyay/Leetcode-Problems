class Solution {
public:
    bool hasAllCodes(string s, int k) {
       
        unordered_set<string> result;
        int total = pow(2, k);
        int n = s.length();
        for(int i = 0; i < n - k + 1 ; i++)
        {
            string st = "";
            for(int j = i; j < i + k; j++)
            {
                st = st + s[j];
            }
            result.insert(st);
            if(result.size() == total) return true;
        }
        
        return result.size() == total;
    }
};