// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    private:
    bool static checkPerfectSquare(long long w)
    {
        long long root = sqrt(w);
        return (root*root == w);
    }
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    vector<pair<long double, long long>> knapsack;
	    for(int i = 0; i < N; i++)
	    {
	        if(!checkPerfectSquare(w[i]))
	        {
	            long double effective_cost = p[i]*1.0d/w[i]*1.0d;
	            knapsack.push_back({effective_cost, w[i]});
	        }
	    }
	    
	    sort(knapsack.rbegin(), knapsack.rend());
	    
	    long double profitable_cost = 0.0d;
	    
	    for(int i = 0; i < knapsack.size(); i++)
	    {
	        long long toTake = min(knapsack[i].second, C)*1.0d;
	        profitable_cost = profitable_cost + toTake * (knapsack[i].first);
	        C = C - toTake;
	    }
	    
	    return profitable_cost;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends