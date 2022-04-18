// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

 #define ll long long 
const int mod = 1e9+7;

class Solution {
  public:
    long long karyTree(int k, int m) {
        // code here
        return expo(k,m);
    }
    
    ll expo(ll base,ll pow )
{
    ll ans=1;
    while(pow)
    {
        if(pow&1)
           ans = (ans *1ll* base)%mod; 

        base = (base * 1ll *base) %mod;
        pow = pow>>1;
    }
    return ans;

}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends