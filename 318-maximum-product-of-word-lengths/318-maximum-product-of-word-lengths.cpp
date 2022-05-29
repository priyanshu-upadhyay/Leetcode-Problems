class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            for(char ch : words[i])
            {
                mp[ch] = 1;
            }
            
            for(int j = i + 1; j < n; j++)
            {
                bool canConsider = true;
                for(char ch : words[j])
                {
                    if(mp.find(ch) != mp.end())
                    {
                        canConsider = false;
                        break;
                    }
                }
                
                if(canConsider)
                {
                    int compute = words[i].length() * words[j].length();
                    result = max(compute, result);
                }
            }
        }
        return result;
    }
};