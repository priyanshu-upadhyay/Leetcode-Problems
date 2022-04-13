class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r = n, c = n, k = 0, l = 0;
        int count = 1;
        vector<vector<int>> result(n, vector<int> (n, 0));
        while(k < r && l < c)
        {
            // Top Row
            for(int i = l; i < c; i++)
            {
                result[k][i] = count++;
            }
            
            k++;  
            
            // Side Column
            for(int i = k; i < r; i++)
            {
                result[i][c-1] = count++;
            }
            
            c--;  
            
            for(int i = c-1; i >= l; i--)
            {
                result[r-1][i] = count++;
            }
            r--;
            
            for(int i = r - 1; i >= k; i--)
            {
                result[i][l] = count++;
            }
            l++;
        }
        return result;
    }
};