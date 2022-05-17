// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        int ans = INT_MAX;
       while(low <= high){
           int mid = (low + high) >> 1;
           ans = min(ans, arr[mid]);
           
           if(arr[mid] >= arr[high]){
               low = mid + 1;
           }
           else {
               high = mid - 1;
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}  // } Driver Code Ends