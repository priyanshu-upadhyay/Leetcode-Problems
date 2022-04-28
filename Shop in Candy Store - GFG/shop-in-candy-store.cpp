// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        // 1 2 3 4
        int minAmt = 0;
        int i = 0, j = N - 1;
        while(i <= j)
        {
            
            minAmt += candies[i];
            i++;
            j -= K;
        }
        
        int maxAmt = 0;
        i = 0, j = N - 1;
        while(i <= j)
        {
            maxAmt += candies[j];
            j--;
            i += K;
        }
        return {minAmt, maxAmt};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends