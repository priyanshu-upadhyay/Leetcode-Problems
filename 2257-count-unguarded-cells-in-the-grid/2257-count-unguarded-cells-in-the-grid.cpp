class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> area(m, vector<int> (n, 0));
        for(auto cor : walls)
        {
            
            area[cor[0]][cor[1]] = -1;
        }
        
        for(auto cor : guards)
        {
            area[cor[0]][cor[1]] = 1;
        }
        for(auto cor : guards)
        {
            // west
            for(int j = cor[1]-1; j >= 0; j--)
            {
                
                if(area[cor[0]][j] == -1 || area[cor[0]][j] == 1) break;
                area[cor[0]][j] = 2;
            }
            
            // east
            for(int j = cor[1]+1; j < n; j++)
            {
                
                if(area[cor[0]][j] == -1 || area[cor[0]][j] == 1) break;
                
                area[cor[0]][j] = 2;
            }
            
            // north
            for(int i = cor[0]-1; i >= 0; i--)
            {
                
                if(area[i][cor[1]] == -1 || area[i][cor[1]] == 1) break;
                area[i][cor[1]] = 2;
            }
            
            // south
            for(int i = cor[0]+1; i < m; i++)
            {
                if(area[i][cor[1]] == -1 || area[i][cor[1]] == 1) break;
                area[i][cor[1]] = 2;
            }
        }
        int count = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(area[i][j] == 0)
                {
                    // cout<<i<<" "<<j<<"\n";
                    count++;
                }
            }
        }
        return count;
        
        
    }
};