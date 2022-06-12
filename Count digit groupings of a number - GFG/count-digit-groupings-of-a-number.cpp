// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    private:
    vector<vector<int>> dp;
    int groups(string& str, int index, int sum)
    {
        if(index == str.length()) return 1;
        int curr_sum = 0;
        int ans = 0;
        if(dp[index][sum] != -1) return dp[index][sum];
        for(int i = index; i < str.length(); i++)
        {
            curr_sum += (str[i] - '0');
            if(curr_sum >= sum)
            {
                ans += groups(str, i+1, curr_sum);
            }
        }
        return dp[index][sum] = ans;
    }
	public:
	int TotalCount(string str){
	    // max sum = 9*n
	    int n = str.length();
	    dp.resize(n, vector<int>(9*n,-1));
	    int result = groups(str, 0, 0);
	    return result;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends