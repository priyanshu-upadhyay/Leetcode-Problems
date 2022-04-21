// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    string recursion(string s, int i, int n)
    {
        if(i == n) return "";
        string result = "";
        if(i == 0 && s[i] != s[i+1])
        {
            result.push_back(s[i]);
        }
        if(i == n-1 && s[i] != s[i-1])
        {
            result.push_back(s[i]);
        }
        if(i>0 && i<n-1 && s[i-1] != s[i] && s[i] != s[i+1])
        {
            result.push_back(s[i]);
        }
        return result + recursion(s, i+1, n);
    }
    string remove(string s){
        int n = s.length();
        string prev = "";
        while(prev != s)
        {   
            prev = s;
            string ans = "";
            int i = 0, n = s.length();
            while(i < n)
            {
                if(i < n-1 && s[i] == s[i+1])
                {
                    while(i < n-1 && s[i] == s[i+1]) i++;
                }
                else
                {
                    ans += s[i];
                }
                i++;
            }
            s = ans;
        }
        
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends