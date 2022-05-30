class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n*m - 1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            int i = mid / m, j = mid % m;    
            // Col me kitni dept h usse farak padta hai row se nhi kyuki wo total to humne pahle he nikal liya h .... division se konse row ka tukda hai and % se use row me kaha h wo....
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return false;
    }
};