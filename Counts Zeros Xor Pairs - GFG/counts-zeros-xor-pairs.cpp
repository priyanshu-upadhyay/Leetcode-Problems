// { Driver Code Starts
// C++ program to find number 
// of pairs in an array such
// that their XOR is 0
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the
// count
long long int calculate(int a[], int n);

// Driver Code
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>>n;
	  int arr[n+1];
	  for( int i=0;i<n;i++)
	        cin>>arr[i];
	    cout << calculate(arr, n)<<endl;
        
	}
	return 0;
}

// } Driver Code Ends


long long int calculate(int a[], int n)
{
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    long long int count = 0;
    for(auto pair : mp)
    {
        int freq = pair.second;
        count  = count + freq*(freq-1) / 2;
    }
    return count;
}
