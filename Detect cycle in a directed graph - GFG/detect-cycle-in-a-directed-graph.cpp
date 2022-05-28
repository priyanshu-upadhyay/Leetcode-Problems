// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
  private:
    bool checkCycleInGraph(int entry, vector<int> adj[], vector<bool>& visited, vector<bool>& dfsVisited)
    {
        visited[entry] = true;
        dfsVisited[entry] = true;
        
        for(int node : adj[entry])
        {
            if(visited[node] == false)
            {
                bool isCycle = checkCycleInGraph(node, adj, visited, dfsVisited);
                if(isCycle) return true;
            }
            else if(dfsVisited[node] == true)
            {
                return true;
            }
        }
        dfsVisited[entry] = false;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int node = 0; node < V; node++)
        {
            if(visited[node] == false)
            {
                bool isCycle = checkCycleInGraph(node, adj, visited, dfsVisited);
                if(isCycle) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends