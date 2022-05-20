// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    void dfs(int start, vector<int> adj[], stack<int>& st, vector<int>& visited1)
    {
        visited1[start] = 1;
        for(int element : adj[start])
        {
            if(visited1[element] == 0)
            {
                dfs(element, adj, st, visited1);
            }
        }
        st.push(start);
    }
    
    void dfs2(int start, vector<int> adj[], vector<int>& visited)
    {
        visited[start] = 1;
        for(int element : adj[start])
        {
            if(visited[element] == 0)
            {
                dfs2(element, adj, visited);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> visited1(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++)
        {
            if(visited1[i] == 0)
            {
                dfs(i, adj, st, visited1);
            }
        }
        vector<int> adj_reversed[V];
        for(int i = 0; i < V; i++)
        {
            for(int element : adj[i])
            {
                adj_reversed[element].push_back(i);
            }
        }
        
        int count = 0;
        vector<int> visited2(V, 0);
        while(!st.empty())
        {
            int element = st.top();
            st.pop();
            if(visited2[element] == 0)
            {
                count++;
                dfs2(element, adj_reversed , visited2);
            }
        }
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends