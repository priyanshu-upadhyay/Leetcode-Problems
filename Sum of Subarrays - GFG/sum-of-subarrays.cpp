// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long arr[], long long n)
    {
        // long long sum = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     long long temp = 0;
        //     for(int j = i; j < n; j++)
        //     {
                
        //         // for(int k = i; k <= j; k++)
        //         // {
        //         //     cout<<arr[k] <<" ";
        //         // }
        //         // cout<<"\n";
        //         temp += arr[j];
        //         sum += temp;
        //     }
        // }
        // return sum;
        
        // Analyis :
        // Start => (n-i)
        // SubArray => (n - i) * i
        // Total = (n-i) + (n-i)*i
        //       = (i + 1) (n - i)
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (((n-i) + (n-i)*i)*arr[i])%1000000007;
        }
        
        return sum%1000000007;
    }
        
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends