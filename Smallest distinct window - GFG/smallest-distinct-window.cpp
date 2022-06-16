// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_map<char,int> mp;
        for(int i=0;i<str.length();i++) mp[str[i]]=0;
        int tc = mp.size(), wc=0 , i=0 , j=0 , ans = INT_MAX;
        while(j<str.length())
        {
            while(wc<tc && j<str.length())
            {
                if(mp[str[j]]==0)  wc++;
                mp[str[j]]++;
                j++;
            }
            while(wc==tc && i<j)
            {
                ans = min(ans,j-i);
                mp[str[i]]--;
                if(mp[str[i]]==0)  wc--;
                i++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends