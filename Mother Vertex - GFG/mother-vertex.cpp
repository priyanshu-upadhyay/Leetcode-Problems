// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    private:
        int dfs(int start, vector<int>adj[], vector<bool>& visited)
        {
            visited[start] = true;
            for(int element : adj[start])
            {
                if(visited[element] == false)
                    dfs(element, adj, visited);
            }
            return start;
        }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
	    int motherVertex = 0; // May be
	    for(int i = 0; i < V; i++)
	    {
	        if(visited[i] == false)
	            motherVertex = dfs(i, adj, visited);
	    }
	    
	    vector<bool> visitedCheck(V, false);
        dfs(motherVertex, adj, visitedCheck);
        for(int i = 0; i < V; i++)
        {
            if(visitedCheck[i] == false) return -1;
        }
        return motherVertex;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends