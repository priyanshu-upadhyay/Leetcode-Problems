// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        int mi = INT_MAX;
        for(int i=1; i<=N; i++){
            vector<bool> vis(N+1, 0);
            int cnt = 0;
            
            queue<int> q;
            q.push(i);
            
            while(!q.empty())
            {
                int n = q.size();
                bool f = 0;
                while(n--){
                    int x = q.front();
                    q.pop();
                    if(vis[x]) continue;
                    
                    vis[x] = 1;
                    
                    for(auto y: adj[x]){
                        if(!vis[y]){
                            f = 1;
                            q.push(y);
                        }
                    }
                    
                }
                if(!f) break;
                ++cnt;
            }
            
            mi = min(mi, cnt);
            
            
        }
        
        return mi;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends