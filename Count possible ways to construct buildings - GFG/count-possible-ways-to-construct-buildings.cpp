// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    long long int mod = 1000000007;
	    vector<long long int> f(N + 1);
	    f[0] = f[1] = 1;
	    for(int i = 2; i <= N; i++)  { f[i] = (f[i-1]%mod + f[i-2]%mod); }
	    long long int ans = (f[N] + f[N-1])%mod;
	    ans = ans * ans;
	    ans %= mod;
	    return int(ans);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends