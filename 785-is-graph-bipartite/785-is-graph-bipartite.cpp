class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, 0);
        
        /*
            0 =>    uncolored
            1 =>    colored
            -1 =>   opp. colored
        */
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(color[i]) continue;
            q.push(i);
            color[i] = 1;
            while(!q.empty())
            {
                int front = q.front();
                for(int element : graph[front])
                {
                    if(!color[element])
                    {
                        color[element] = -color[front];
                        q.push(element);
                    }
                    else if(color[element] == color[front])
                    {
                        return false;
                    }
                }
                q.pop();
            }
            
        }
        return true;
        
    }
};