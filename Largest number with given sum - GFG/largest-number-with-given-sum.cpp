// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:

    string largestNumber(int n, int sum)
    {
        string s (n, 0);
       for(int i=0; i<n; i++){
           for(int j=9; j>=0; j--){
               if(j<=sum){
                   s[i] = j+'0';
                   sum -= j;
                   break;
               }
           }
       }
       return sum == 0 ? s : "-1";
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends