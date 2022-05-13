class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = -1, j = -1;
        int n = s.length();
        int maxLen = 0;
        unordered_map<char, int> mp;
        while(true)
        {
            int f1 = 0, f2 = 0;
            while(i < n - 1)
            {
                f1 = 1;
                i++;
                mp[s[i]]++;
                if(mp[s[i]] == 2)
                {
                    break;
                }
                else
                {
                    maxLen = max(i - j, maxLen);
                }
            }
            
            while(j < i)
            {
                f2 = 1;
                j++;
                mp[s[j]]--;
                if(mp[s[j]] == 1)
                {
                    break;
                }
            }
            
            if(f1 == 0 && f2 == 0) break;
        }
        return maxLen;
    }
};