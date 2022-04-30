class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0, end = n * m - 1;
        
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            int row = mid / m, column = mid % m;
            if(matrix[row][column] == target)
            {
                return true;
            }
            
            if(matrix[row][column] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};