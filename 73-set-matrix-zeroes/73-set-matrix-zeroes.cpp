class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        
        bool isRow = false, isCol = false;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i][0] == 0) isRow = true;
        }
        
        for(int j = 0; j < m; j++)
        {
            if(arr[0][j] == 0) isCol = true;
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[0][j] = 0;
                    arr[i][0] = 0;
                }
            }
        }
        
        for(int i = 1; i < n; i++)
        {
            if(arr[i][0] == 0)
            {
                for(int j = 0; j < m; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++)
        {
            if(arr[0][i] == 0)
            {
                for(int j = 0; j < n; j++)
                {
                    arr[j][i] = 0;
                }
            }
        }
        
        if(isRow)
        {
            for(int i = 0; i < n; i++)
            {
                arr[i][0] = 0;
            }
        }
        
        if(isCol)
        {
            for(int j = 0; j < m; j++)
            {
                arr[0][j] = 0;
            }
        }
    }
};