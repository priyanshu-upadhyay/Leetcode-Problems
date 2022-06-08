class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        
        while( i < j)
        {
            if(s[i] == s[j]) i++, j--;
            else return 2;    // pahle saare 'a' remove kardo the saare 'b'
        }
        return 1;    // atleast 1 answer to hoga he 
    }
};