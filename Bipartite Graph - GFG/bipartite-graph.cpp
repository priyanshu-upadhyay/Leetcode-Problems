// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool func(vector<int>adj[],int src,vector<int>&vis){
       queue<pair<int,int>>q;
       q.push({src,0});
       while(!q.empty()){
           pair<int,int> a=q.front();
           q.pop();
           if(vis[a.first]!=-1){
               if(a.second!=vis[a.first])return false;
           }
           vis[a.first]=a.second;
           for(auto j:adj[a.first]){
               if(vis[j]==-1){
                   q.push({j,1-a.second});
               }
           }
       }
       return true;
   }
bool isBipartite(int V, vector<int>adj[]){
    vector<int>vis(V,-1);
    bool ans=true;
    for(int i=0;i<V;i++){
        if(vis[i]==-1){
            ans&=func(adj,i,vis);
        }
    }
    return ans;

}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends