class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            int i = mid / m, j = mid % m;
            if(target == matrix[i][j])
            {
                return true;
            }
            
            if(target > matrix[i][j])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return false;
    }
};