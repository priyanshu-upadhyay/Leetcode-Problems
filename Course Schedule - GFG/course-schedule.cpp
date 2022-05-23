// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  private:
    bool dfs(int start, vector<int> adj[], vector<int>& visited, vector<int>& dfsVisited, vector<int>& path)
    {
        
        visited[start] = 1;
        dfsVisited[start] = 1;
        for(int node : adj[start])
        {
            if(!visited[node])
            {
                bool isCycle = dfs(node, adj, visited, dfsVisited, path);
                if(isCycle) return true;
            }
            else if(visited[node] && dfsVisited[node])
            {
                return true;
            }
        }
        dfsVisited[start] = 0;
        path.push_back(start);
        return false;
    }
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> adj[n];
        for(vector<int> pair : prerequisites)
        {
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> visited(n);
        vector<int> dfsVisited(n);
        vector<int> path;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                bool isCycle = dfs(i, adj, visited, dfsVisited, path);
                if(isCycle) return {};
            }
        }
        reverse(path.begin(), path.end());
        return path;
        
    }
};

// { Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends