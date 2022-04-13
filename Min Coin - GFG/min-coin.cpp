// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoinHelper(vector<int> nums, int amt, int i, vector<vector<int>> &dp)
	{
	    if(amt == 0)
	    {
	        return 0;
	    }
	    if(i == 0)
	    {
	        return INT_MAX - 1;
	    }
	    if(dp[i][amt] != -1)
	    {
	        return dp[i][amt];
	    }
	    if(amt - nums[i-1] >= 0)
	    {
	        return dp[i][amt] = min(1 + minCoinHelper(nums, amt - nums[i-1],  i, dp), minCoinHelper(nums, amt,  i - 1, dp));
	    }
	    return dp[i][amt] = minCoinHelper(nums, amt,  i - 1, dp);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    int n = nums.size();
	    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));
	    int result = minCoinHelper(nums, amount, n, dp);
	    return result == INT_MAX-1 ? -1 : result;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends