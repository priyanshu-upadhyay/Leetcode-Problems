// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n, INT_MAX);
	    
	    dis[0] = 0;
	    
	    for(int i = 0; i < n-1; i++)
	    {
	        for(vector<int> edge : edges)
	        {
	            int u = edge[0];
	            int v = edge[1];
	            int w = edge[2];
	            
	            if(dis[u] != INT_MAX && dis[u] + w < dis[v])
	            {
	                dis[v] = dis[u] + w;
	            }
	        }
	    }
	    
	    // Uske baad bhi saala kum ho rha h matlab -ve weight h uske andar jo kam kar rha h 
	    for(vector<int> edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dis[u] != INT_MAX && dis[u] + w < dis[v])
            {
                return 1;
            }
        }
        return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends