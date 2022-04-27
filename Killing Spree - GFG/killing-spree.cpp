// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int squareSum(long long int n)
    {
        return n*(n+1)*(2*n+1) / 6;
    }
    long long int killinSpree(long long int n)
    {
        long long int start = 1, end = sqrt(n);
        long long int ans = 1;
        while(start <= end)
        {
            long long int mid = (start + end)/2;
            long long int sum = squareSum(mid);
            if(sum <= n)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends