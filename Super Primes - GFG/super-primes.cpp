// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    vector<int> prime_sieve(n + 1, 1); //  Set all Number to Prime First
	    prime_sieve[0] = 0; // set prime status of zero to false;
	    prime_sieve[1] = 0; //  According to morder mathematics time numbers has two distinct factors (1, itself)
	    for(int i = 2; i*i <= n; i++)
	    {
	        if(prime_sieve[i] == 1)
	        {
	            for(int j = i*i; j <= n; j = j + i)
	            {
	                prime_sieve[j] = 0;
	            }
	        }
	    }
	    int count = 0;
	    for(int i = 2; i <= n; i++)
	    {
	        if(prime_sieve[i] == 1 && prime_sieve[i-2] == 1)
	        {
	            count++;
	        }
	    }
	    return count;
	    
	    
	    
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
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends