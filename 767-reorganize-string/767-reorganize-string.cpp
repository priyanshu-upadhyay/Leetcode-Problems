class Solution {
public:
    string reorganizeString(string s) {
        
        vector<int> freq(26, 0);
        int n = s.length();
        int maxFreq = 0;
        char maxFreqChar = 'a';
        for(int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
            int currFreq = freq[s[i] - 'a'];
            if(maxFreq < currFreq)
            {
                maxFreq = currFreq;
                maxFreqChar = s[i];
            }
        }

        if(maxFreq > (n+1)/2)         // odd hoga to dikkat aayegi islye... || आधे से ज्यदा हुआ तो नहीं Possible है 
        {
            return "";
        }
        
        string result;
        result.append(n, '.');
        int i = 0;
        
        while(freq[maxFreqChar - 'a'] > 0)
        {
            result[i] = maxFreqChar;
            i = i + 2;
            freq[maxFreqChar - 'a']--;
        }
        
        for(int j = 0; j < n; j++)
        {
            while(freq[s[j] - 'a'] > 0)
            {
                if(i >= n) i = 1;
                result[i] = s[j];
                freq[s[j] - 'a']--;
                i = i + 2;
            }
        }
        return result;
    }
};