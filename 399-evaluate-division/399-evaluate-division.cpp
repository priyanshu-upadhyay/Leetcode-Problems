class Solution {
public:
    
    void dfs(string start, string end, unordered_map<string, vector<pair<string, double>>>& mp, unordered_set<string> &visited, double &ans, double temp, int check)
    {
        if(visited.find(start) == visited.end())
        {
            if(start == end)
            {
                ans = temp;
                check = 1;
                return;
            }
            else
            {
               visited.insert(start);
                for(auto pair : mp[start])
                {
                    string newStart = pair.first;
                    double value = pair.second;
                    if(check == 1)
                    {
                        return;
                    }
                    dfs(newStart, end, mp, visited, ans, temp*value, check);
                    if(check == 1)
                    {
                        return;
                    }
                }
            }
        }

    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> mp;
        
        for(int i = 0; i < equations.size(); i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        vector<double> result;
        for(int i = 0; i < queries.size(); i++)
        {
            string start = queries[i][0];
            string end = queries[i][1];
            unordered_set<string> visited;
            
            double ans = -1.00;
            if(mp.find(start) != mp.end() && mp.find(end) != mp.end())
            {
                dfs(start, end, mp, visited, ans, 1, 0);
            }
            result.push_back(ans);
        }
        return result;
    }
};