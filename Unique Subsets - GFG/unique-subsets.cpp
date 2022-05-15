// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
   public:
   #define vv vector<vector<int>>
   void subs(vv &ans,vector <int> &arr,int i,vector <int> a)
   {
       if(i==arr.size())
       {
           ans.push_back(a);
           return;
       }
       
       int u=i;
       while(u<arr.size() && arr[u]==arr[i])
           u++;
        
       subs(ans,arr,u,a);   
       for(int j=i;j<u;j++)
       {
           a.push_back(arr[j]);
           subs(ans,arr,u,a);
       }
   }
   vector<vector<int> > AllSubsets(vector<int> arr, int n)
   {
       // code here
       vv ans;
       vector <int> a;
       sort(arr.begin(),arr.end());
       subs(ans,arr,0,a);
       sort(ans.begin(),ans.end());
       return ans;
   }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends