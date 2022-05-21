// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int N, vector<int> Arr){
        vector<pair<int, int>> comp;
        for(int i = 0; i < N; i++)
        {
            comp.push_back({Arr[i], i});
        }
        sort(comp.begin(), comp.end());
        vector<int> maxIndex(N);
        int index = -1;
        for(int i = 0; i < N; i++)
        {
            if(comp[i].second > index)
            {
                maxIndex[comp[i].second] = -1;
            }
            else
            {
                maxIndex[comp[i].second] = index;
            }
            index = max(index, comp[i].second);
        }
        return maxIndex;
        
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends