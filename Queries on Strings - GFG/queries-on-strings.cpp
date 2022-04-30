// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<int>SolveQueris(string str, vector<vector<int>>Query){
	    int n = str.length();
	    vector<vector<int>> dp(n + 1, vector<int> (26, 0));
	    /* Hume ye dekhna h .. 
	       a ka count pos 1 
	       b ka count pos 2
	       c ka count pos 3
	   */
	   for(int i = 1; i < n+1; i++)
	   {
	       for(int j = 0; j < 26; j++)
	       {
	           dp[i][j] = dp[i-1][j];
	       }
	       int pos = str[i-1] - 'a';
	       dp[i][pos]++;
	   }
	   vector<int> result;
	   for(vector<int> q : Query)
	   {
	       int start = q[0], end = q[1], count = 0;
	       for(int i = 0; i < 26; i++)
	       {
	           if(dp[end][i] - dp[start - 1][i] > 0)  //  iska matlab hai kuch ka kuch no. ko char h uske andar
	           {
	               count++;
	           }
	       }
	       result.push_back(count);
	   }
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
		int q;
		cin >> q;
		vector<vector<int>>Query;
		for(int i = 0; i < q; i++){
			int l, r;
			cin >> l >> r;
			Query.push_back({l, r});
		}
		Solution obj;
		vector<int> ans = obj.SolveQueris(str, Query);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends