// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        int minLength = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            int currLength = ar[i].length();
            minLength = min(minLength, currLength);
            
        }
        
        string result = "";
        
        for(int i = 0; i < minLength; i++)
        {
            int f = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(ar[0][i] != ar[j][i])
                {
                    f = 1;
                    break;
                }
            }
            if(f == 0)
            {
                result.push_back(ar[0][i]);
            }
            else
            {
                break;
            }
        }
        
        return result == "" ? "-1" : result;
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends