// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    typedef pair<int, int> pi;
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V, false);
        vector<int> distance(V, 0);
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        pq.push({0, S});
        while(!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            if(visited[top.second] == false)
            {
                visited[top.second] = true;
                distance[top.second] = top.first;
                for(vector<int> edge : adj[top.second])
                {
                    pq.push({top.first + edge[1], edge[0]});
                }
            }
        }
        return distance;
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends