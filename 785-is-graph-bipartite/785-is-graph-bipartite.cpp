class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        set<int> a, b;
        
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        vector<int> visited(graph.size());
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(!visited[p.first])
            {
                for(int i = 0; i < graph[p.first].size(); i++)
                {
                    if(p.second == 0)
                    {
                        b.insert(graph[p.first][i]);
                        q.push(make_pair(graph[p.first][i],1));
                    }
                    else
                    {
                        a.insert(graph[p.first][i]);
                        q.push(make_pair(graph[p.first][i],0));
                    }
                }
                visited[p.first] = 1;
            }
            
        }
        
        for(int i = 0; i < graph.size(); i++)
        {
            if(!visited[i])
            {
                if(a.find(i) != a.end())
                {
                    for(int j = 0; j < graph[i].size(); j++)
                    {
                        b.insert(graph[i][j]);
                    }
                }
                else if(b.find(i) != b.end())
                {
                    for(int j = 0; j < graph[i].size(); j++)
                    {
                        a.insert(graph[i][j]);
                    }
                }
                else
                {
                    a.insert(i);
                    for(int j = 0; j < graph[i].size(); j++)
                    {
                        b.insert(graph[i][j]);
                    }
                }

                visited[i] = 1;
                }
        }
        
        if((a.size()+b.size()) <= graph.size())
        {
            return true;
        }
        return false;
        
        
        
        
        
        
        
        
        
    }
};