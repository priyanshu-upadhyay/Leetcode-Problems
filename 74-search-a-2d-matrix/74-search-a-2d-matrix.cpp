class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        
        for(vector<int> each : matrix)
        {
            if(target >= each[0] && target <= each[m-1])
            {
                int low = 0, high = m - 1;
                
                while(low <= high)
                {
                    int mid = (low + high) >> 1;
                    if(each[mid] == target)
                    {
                        return true;
                    }
                    if(each[mid] > target)
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};