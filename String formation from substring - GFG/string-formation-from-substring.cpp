// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isRepeat(string s)
	{
	    int n = s.length();
	    
	    for(int i = 0; i < n; i++)
	    {
	        int steps = i + 1;
	        string comp_str = s.substr(0, steps);
	        int f = 0;
	        for(int j = i + 1; j < n; j = j + steps)
	        {
	            string curr = s.substr(j, steps);
	            if(curr != comp_str) 
	            {
	                f = 1;
	                break;
	            }
	        }
	        if(f == 0 && i < n-1) 
	        {
	           // cout<<comp_str<<"\n";
	            return 1;
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends