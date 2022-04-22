class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        vector<int> row(n), column(m);
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(arr[i][j] == 0)
                {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(row[i] == 1)
            {
                for(int k = 0; k < m; k++)
                {
                    arr[i][k] = 0;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(column[i] == 1)
            {
                for(int k = 0; k < n; k++)
                {
                    arr[k][i] = 0;
                }
            }
        }
    }
};